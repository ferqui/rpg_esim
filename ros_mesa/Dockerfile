FROM ros:melodic

RUN apt-get update && apt-get install -y libtool-bin autoconf python-pip libx11-dev libxext-dev x11proto-core-dev x11proto-gl-dev libglew-dev freeglut3-dev bison flex

# Build Mesa
RUN apt-get install -y wget pkg-config zlib1g-dev llvm-dev
RUN wget https://mesa.freedesktop.org/archive/mesa-18.2.4.tar.xz
RUN tar xf mesa-18.2.4.tar.xz
RUN mkdir mesa-18.2.4/build
WORKDIR mesa-18.2.4/build

RUN ../configure --disable-dri \
               --disable-egl \
               --disable-gbm \
               --with-gallium-drivers=swrast,swr \
               --with-platforms=x11 \
               --prefix=/usr/local/ \
               --enable-gallium-osmesa \
               --disable-xvmc --disable-vdpau --disable-va \
               --with-swr-archs=avx \
               --enable-glx=gallium-xlib

RUN make && make install

# Setup our environment variables.
ENV XVFB_WHD="1920x1080x24"\
    DISPLAY=":99" \
    LIBGL_ALWAYS_SOFTWARE="1" \
    GALLIUM_DRIVER="softpipe"