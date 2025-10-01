#include <chrono>
#include <functional>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include <example_interfaces/msg/int64.hpp>

using namespace std::chrono_literals;

class Publicar : public rclcpp::Node
{
  public:
    Publicar()
    : Node("number_publisher")
    {
      publicar = this->create_publisher<example_interfaces::msg::Int64>("number", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&Publicar::timer_callback, this));
    }

  private:
    void timer_callback()
    {
      auto message = example_interfaces::msg::Int64();
      message.data = 2;
      RCLCPP_INFO(this->get_logger(), "Publicando: '%ld'", message.data);
      publicar->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publicar;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Publicar>());
  rclcpp::shutdown();
  return 0;
}