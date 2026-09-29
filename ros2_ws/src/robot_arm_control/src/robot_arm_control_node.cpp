#include <memory>

#include "rclcpp/rclcpp.hpp"

class RobotArmControlNode : public rclcpp::Node
{
public:
    RobotArmControlNode()
        : Node("robot_arm_control_node")
    {
        RCLCPP_INFO(
            get_logger(),
            "Robot arm control node started.");
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<RobotArmControlNode>();

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}
