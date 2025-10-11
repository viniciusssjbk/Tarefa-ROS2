#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Publicar2 : public rclcpp::Node
{
public:
    Publicar2() : Node("publicar_2")
    {

        publicar = this->create_publisher<std_msgs::msg::String>("topico2", 10);

        subscriber = this->create_subscription<std_msgs::msg::String>(
            "topico1",
            10,
            std::bind(&Publicar2::tempovoltar2, this, std::placeholders::_1)
        );
    }

private:
    void tempovoltar2(const std_msgs::msg::String & msg)
    {
        auto message = std_msgs::msg::String();
        int tipo = std::stoi(msg.data);
        if(tipo%2==0){
        message.data = msg.data;
        };
        RCLCPP_INFO(this->get_logger(), "Recebido: '%s' | Publicando: '%s'", msg.data.c_str(), message.data.c_str());
        publicar->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publicar;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Publicar2>());
    rclcpp::shutdown();
    return 0;
}
