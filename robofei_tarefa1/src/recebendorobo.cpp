#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <memory>
/*Criando uma função chamada Roborecebido*/
class Roborecebido : public rclcpp::Node {
public:
/*Criando um no chamado 'rebendo_aviso' onde ele é do tipo <std_msgs::msg::String>*/
/*O topic imprime oq ele esta recebendo*/
  Roborecebido() : Node("rebendo_aviso") {
    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "topic", 10,
      std::bind(&Roborecebido::topic_callback, this, std::placeholders::_1));
  }

private:
/*Aqui vai aparecer a mensagem Recebendo: 'A mensagem que foi publicada para ele'*/
  void topic_callback(const std_msgs::msg::String::SharedPtr msg) const {
    RCLCPP_INFO(this->get_logger(), "Recebendo: '%s'", msg->data.c_str());
  }

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Roborecebido>());
  rclcpp::shutdown();
  return 0;
}
