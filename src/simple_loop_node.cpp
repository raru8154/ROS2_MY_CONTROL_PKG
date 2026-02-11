#include <rclcpp/rclcpp.hpp>

class SimpleLoopNode : public rclcpp::Node
{
public:
  SimpleLoopNode() : Node("simple_loop_node")
  {
    // 500msごとにtimer_callbackを呼ぶ
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(500),
      std::bind(&SimpleLoopNode::timer_callback, this));
  }

private:
  void timer_callback()
  {
    RCLCPP_INFO(this->get_logger(), "Control Loop Running... time: %f", this->now().seconds());
  }

  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SimpleLoopNode>();
  rclcpp::shutdown();
  return 0;
}