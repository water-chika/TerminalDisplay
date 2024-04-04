#include <glfwpp.hpp>
#include <cassert>
#include <renderer.hpp>

class terminal_display {
public:
	terminal_display() : m_window{}, m_renderer{} {
		glfwpp::init();
		create_window();
		transfer_surface();
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
	void transfer_surface() {
		VkSurfaceKHR surface{};
		VkResult res = glfwpp::create_surface(m_renderer.get_instance(), m_window, nullptr, &surface);
		assert(res == VK_SUCCESS);
		assert(surface);
		m_renderer.set_surface(surface);
	}
	glfwpp::window m_window;
	terminal_display_vulkan_renderer m_renderer;
};