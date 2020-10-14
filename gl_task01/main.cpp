// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

#include <iostream>

int main()
{
	std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;

	glfwInit();
	// �����汾��(Major)�ʹΰ汾��(Minor)����Ϊ3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// ʹ�ú���ģʽ(Core-profile)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// �������û��������ڵĴ�С
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// ����һ�����ڶ���
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// �����Ǵ��ڵ�����������Ϊ��ǰ�̵߳���������
	glfwMakeContextCurrent(window);


	// ��ʼ��glew
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	// glfwWindowShouldClose����������ÿ��ѭ���Ŀ�ʼǰ���һ��GLFW�Ƿ�Ҫ���˳���
	// ����ǵĻ��ú�������trueȻ����Ϸѭ��������ˣ�֮��Ϊ���ǾͿ��Թر�Ӧ�ó����ˡ�
	while (!glfwWindowShouldClose(window))
	{
		// glfwPollEvents���������û�д���ʲô�¼�������������롢����ƶ��ȣ���
		// Ȼ����ö�Ӧ�Ļص�����������ͨ���ص������ֶ����ã�������һ������Ϸѭ����
		// ��ʼ�����¼���������
		glfwPollEvents();
		// glfwSwapBuffers�����ύ����ɫ���壨����һ��������GLFW����ÿһ��������ɫ
		// �Ĵ󻺳壩��������һ�����б��������ƣ����ҽ�����Ϊ�����ʾ����Ļ�ϡ�
		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}