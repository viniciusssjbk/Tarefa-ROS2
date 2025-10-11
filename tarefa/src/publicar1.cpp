#include <iostream>
#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"
using namespace std::chrono_literals;  
class publicar1 : public rclcpp::Node
{
    public:
    publicar1():Node("publicar_1")
    {
        publicar = this->create_publisher<std_msgs::msg::String>("topico1", 10);
        tempo = this->create_wall_timer(500ms, std::bind(&publicar1::tempovolta, this));
    }
    private:
    void tempovolta(){
            auto message = std_msgs::msg::String();
            message.data = "10";
            RCLCPP_INFO(this->get_logger(), "publicando: '%s'", message.data.c_str());
            publicar->publish(message);
            message.data = "15";
            RCLCPP_INFO(this->get_logger(), "publicando: '%s'", message.data.c_str());
            publicar->publish(message);
        
    }
    rclcpp::TimerBase::SharedPtr tempo;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publicar;
    
};



int main(int argc, char * argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<publicar1>());
    rclcpp::shutdown();
    return 0;
}