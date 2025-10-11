#include <iostream>
#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"
using namespace std::chrono_literals;

class Publicar3:public rclcpp::Node{

    public:
    Publicar3():Node("publicar_3"){
        publicar= this->create_publisher<std_msgs::msg::String>("topico3",10);
        subscriber= this->create_subscription<std_msgs::msg::String>("topico2",10,std::bind(&Publicar3::tempovoltar3, this, std::placeholders::_1));

    }
    private:
    void tempovoltar3(const std_msgs::msg::String & msg){
        auto message = std_msgs::msg::String();
        std::cout << "Digite um numero:\n";
        std::cin >> message.data;
        int msg1, msg2;
        msg1 = std::stoi(message.data);
        msg2 = std::stoi(msg.data);
        if(msg1==msg2){
            RCLCPP_INFO(this->get_logger(), "Você acertou o numero!!!");
        }else{
            RCLCPP_INFO(this->get_logger(), "Você errou o numero!!!");
        }
        publicar->publish(message);
    }
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publicar;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber;

};
int main(int arc,char * argv[]){
    rclcpp::init(arc, argv);
    rclcpp::spin(std::make_shared<Publicar3>());
    rclcpp::shutdown();
}
