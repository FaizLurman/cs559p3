#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "object.h"
#include "shader.h"
#include "fbo.h"

class JumboTron : public Object
{
public:
	JumboTron();
	
	bool InitializeCylinder();
	bool InitializeScreen();

	virtual void Draw(const glm::ivec2 & size);
	virtual void Draw(const glm::mat4 & projection, glm::mat4 modelview, const glm::ivec2 & size, GLint level, GLint shader, const float time = 0);
	void DrawScreen(const glm::mat4 & projection, glm::mat4 modelview, const glm::ivec2 & size, FrameBufferObject fbo, GLint screen, const float time = 0);
	void TakeDown();
	Shader shader;
	ADSShader adsShader;
	Shader solid_color;

private:
	void BuildNormalVisualizationGeometry();
	glm::vec4 colors[2];
	std::vector<VertexAttributesPCNT> vertices;
	typedef Object super;
	float time;
};