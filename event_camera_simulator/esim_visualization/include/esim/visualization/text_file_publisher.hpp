#pragma once

#include <esim/common/types.hpp>
#include <esim/visualization/publisher_interface.hpp>
#include <fstream>

namespace event_camera_simulator {

class TextFilePublisher : public Publisher
{
public:
  TextFilePublisher(const std::string& path_to_events_text_file, size_t num_cameras);
  ~TextFilePublisher();

  virtual void eventsCallback(const EventsVector& events) override; // will be called when new events are available

  static Publisher::Ptr createFromGflags(size_t num_cameras);


private:
  std::ofstream events_text_file_;
};

} // namespace event_camera_simulator