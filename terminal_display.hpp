#include <glfwpp.hpp>
#include <cassert>
#include <renderer.hpp>

class terminal_display {
public:
	terminal_display() : m_window{} {
		glfwpp::init();
		create_window();
	}
	~terminal_display() {
		destroy_window();
		glfwpp::terminate();
	}
	void run() {
		while (!glfwpp::window_should_close(m_window)) {
			glfwpp::poll_events();
		}
	}
private:
	void create_window() {
		glfwpp::window_hint(GLFW_CLIENT_API, GLFW_NO_API);
		m_window.create(640, 480, "terminal display", nullptr, nullptr);
	}
	void destroy_window() {
		m_window.destroy();
	}
	glfwpp::window m_window;
	terminal_display_vulkan_renderer m_renderer;
};