#include <vector>

#include "OpenGLHepler.h"
#include "toolFunctions.h"
#include "ShaderProgram.h"
#include "Geometry.h"

void framebufferSizeCallback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebufferSizeCallback(GLFWwindow *window, int width, int height){
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: initialize and configure
// ------------------------------
GLFWwindow* initOpenGL() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);

    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    
    return window;
}

// render loop
// -----------
void renderToWindow(GLFWwindow* window) {
    while (!glfwWindowShouldClose(window)) {
        // input
        // -----
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

// render loop
// -----------
void renderToWindow(GLFWwindow* window, ShaderProgram &sp, Geometry& g) {
    while (!glfwWindowShouldClose(window)) {
        // input
        // -----
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        float time_v = glfwGetTime(); 

        sp.useProgram();
        sp.setUniform("time", time_v);

        // glDrawArrays(GL_TRIANGLES, 0, 3);
        g.drawTriangle();

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

bool checkProgramState(unsigned int program_id) {
    int success;
    glGetProgramiv(program_id, GL_COMPILE_STATUS, &success);
    if (success) {
        return true;
    }

    char log[512];
    glGetProgramInfoLog(program_id, 512, NULL, log);
    std::cout << log << "\n";
    return false;
}

int main(){
    // create a window
    GLFWwindow *window = initOpenGL();
    if (window == NULL) {
        return -1;
    }

    ShaderProgram shader_program;
    shader_program.setVertexShader("VertexShader.glsl");
    shader_program.setFragmentShader("FragmentShader.glsl");
    shader_program.linkProgram();

    unsigned int vbo_id, vao_id, ebo_id;
    glGenVertexArrays(1, &vao_id);
    glGenBuffers(1, &vbo_id);
    glGenBuffers(1, &ebo_id);

    Geometry *g = new Geometry();
    g->addVertex(Vertex(Vec3(-0.9f,  0.9f, 0.0f), Color3(1, 0, 0)));
    g->addVertex(Vertex(Vec3(-0.9f, -0.9f, 0.0f), Color3(0, 1, 0)));
    g->addVertex(Vertex(Vec3( 0.9f, -0.9f, 0.0f), Color3(0, 0, 1)));
    g->addVertex(Vertex(Vec3( 0.9f,  0.9f, 0.0f), Color3(1, 1, 1)));

    g->addOrder(TriangleOrder(0, 1, 2));
    g->addOrder(TriangleOrder(2, 3, 0));

    g->bindVAO(vao_id);
    g->bindVBO(vbo_id);
    g->bindEBO(ebo_id);
    g->setBufferData();

    renderToWindow(window, shader_program, *g);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}
