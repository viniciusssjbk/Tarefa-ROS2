
/*Incluindo algumas funcionalidades*/
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <memory>

using namespace std::chrono_literals;
/*Criando uma função Robopublica*/
class Robopublica : public rclcpp::Node {
public:
/*Criando um no chamado no_robo onde ele vai gerar uma mensagem do tipo std_msgs::msg::String*/
/*essa mensagem será publicada a cada 1 segundo*/
  Robopublica() : Node("no_robo"){
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    timer_ = this->create_wall_timer(
      1000ms, std::bind(&Robopublica::timer_callback, this));
  }

private:
  void timer_callback() {
    /*A mensagem vai ser 'Tarefa concluida!!!'*/
    auto message = std_msgs::msg::String();
    message.data = "Tarefa concluida!!!";
    publisher_->publish(message);
  }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Robopublica>());
  rclcpp::shutdown();
  return 0;
}
