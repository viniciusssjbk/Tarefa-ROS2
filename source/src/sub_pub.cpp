#include <chrono>
#include <functional>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include <example_interfaces/msg/int64.hpp>

using std::placeholders::_1;
using namespace std::chrono_literals;
int contar = 10;
class subpub : public rclcpp::Node

{
  public:
    subpub()
    : Node("number_conter")
    {
        receber = this->create_subscription<example_interfaces::msg::Int64>(
        "number", 10, std::bind(&subpub::topic_callback, this, _1));
        publicar = this->create_publisher<example_interfaces::msg::Int64>("number_count", 10);
        timer_ = this->create_wall_timer(
        500ms, std::bind(&subpub::timer_callback, this));

    }

  private:
  
    void topic_callback(const example_interfaces::msg::Int64::SharedPtr msg) const
    {
      RCLCPP_INFO(this->get_logger(), "contando: ", msg->data);
      contar += msg->data;
      
      
    
    }
    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr receber;
  private:
    void timer_callback()
    {
      auto message = example_interfaces::msg::Int64();
      message.data = contar;
      RCLCPP_INFO(this->get_logger(), "data: ", contar);
      publicar->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publicar;
};



int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<subpub>());
  rclcpp::shutdown();
  return 0;
}