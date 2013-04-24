/*	

*/

#include <iostream>
#include "Obstacle.h"

using namespace std;
using namespace glm;

Obstacle::Obstacle() : Object()
{
	vec4 lighter_color(MakeColor(255, 69, 0, 1.0f));
	vec4 darker_color = vec4(vec3(lighter_color) /* 2.0f / 3.0f*/, 1.0f);
	this->colors[0] = lighter_color;
	this->colors[1] = lighter_color;
}


void Obstacle::BuildNormalVisualizationGeometry()
{
	const float normal_scalar = 0.125f;
	for (int j = 1; j <= 3; ++j)
	{
		this->normal_vertices.push_back(VertexAttributesP(this->vertices[this->vertices.size() - j].position));
		this->normal_vertices.push_back(VertexAttributesP(this->vertices[this->vertices.size() - j].position + this->vertices[this->vertices.size() - j].normal * normal_scalar));
		this->normal_indices.push_back(this->normal_vertices.size() - 2);
		this->normal_indices.push_back(this->normal_vertices.size() - 1);
	}
}

float Obstacle::getTime()
{
	return 0.0f;
}

vec3 Obstacle::getPostion()
{
	return this->position;
}

void Obstacle::setPosition(vec3 pos)
{
	position = pos;
}

bool Obstacle::Initialize(int height, int width, int shader)
{
	if (this->GLReturnedError("Top::Initialize - on entry"))
		return false;

	if (!super::Initialize())
		return false;

	this->position = position;

	//slices *= 4;
	mat4 m;
	const vec3 n = normalize(vec3(1.0f, 1.0f, 1.0f));
	int steps = 6;
	float x, y, z;
	vec4 location;
	vec3 color2 = MAGENTA;

	const float increment_height = height/steps;
	const float increment_width = width/steps;

	//create the wall (wall one)
	VertexAttributesPCN cur_bottom_vertex, cur_top_vertex, nxt_bottom_vertex, nxt_top_vertex;
	x = -width/2.0f;
	y = height;
	z = -width/2.0f;
	
	location = vec4(x, y, z, 1.0f);
	cur_top_vertex.position = vec3(m * location);
	cur_top_vertex.color = color2;
	cur_top_vertex.normal = vec3(0.0f, 0.0f, 1.0f);

	x = width/2.0f;
	location = vec4(x, y, z, 1.0f);
	nxt_top_vertex.position = vec3(m * location);
	nxt_top_vertex.color = color2;
	nxt_top_vertex.normal = vec3(0.0f, 0.0f, 1.0f);

	y = 0.0f;
	location = vec4(x, y, z, 1.0f);
	nxt_bottom_vertex.position = vec3(m * location);
	nxt_bottom_vertex.color = color2;
	nxt_bottom_vertex.normal = vec3(0.0f, 0.0f, 1.0f);

	x = -width/2.0f;
	location = vec4(x, y, z, 1.0f);
	cur_bottom_vertex.position = vec3(m * location);
	cur_bottom_vertex.color = color2;
	cur_bottom_vertex.normal = vec3(0.0f, 0.0f, 1.0f);

	this->vertices.push_back(cur_top_vertex);
	this->vertices.push_back(cur_bottom_vertex);
	this->vertices.push_back(nxt_top_vertex);
	this->vertices.push_back(nxt_bottom_vertex);

	this->vertex_indices.push_back(vertices.size() - 1);
	this->vertex_indices.push_back(vertices.size() - 4);
	this->vertex_indices.push_back(vertices.size() - 3);
			
	this->vertex_indices.push_back(vertices.size() - 1);
	this->vertex_indices.push_back(vertices.size() - 2);
	this->vertex_indices.push_back(vertices.size() - 4);

	//wall 2
	x = -width/2.0f;
	y = height;
	z = width/2.0f;
	
	location = vec4(x, y, z, 1.0f);
	cur_top_vertex.position = vec3(m * location);
	cur_top_vertex.color = color2;
	cur_top_vertex.normal = vec3(1.0f, 0.0f, 0.0f);

	z = -width/2.0f;
	location = vec4(x, y, z, 1.0f);
	nxt_top_vertex.position = vec3(m * location);
	nxt_top_vertex.color = color2;
	nxt_top_vertex.normal = vec3(1.0f, 0.0f, 0.0f);

	y = 0.0f;
	location = vec4(x, y, z, 1.0f);
	nxt_bottom_vertex.position = vec3(m * location);
	nxt_bottom_vertex.color = color2;
	nxt_bottom_vertex.normal = vec3(1.0f, 0.0f, 0.0f);

	z = width/2.0f;
	location = vec4(x, y, z, 1.0f);
	cur_bottom_vertex.position = vec3(m * location);
	cur_bottom_vertex.color = color2;
	cur_bottom_vertex.normal = vec3(1.0f, 0.0f, 0.0f);

	this->vertices.push_back(cur_top_vertex);
	this->vertices.push_back(cur_bottom_vertex);
	this->vertices.push_back(nxt_top_vertex);
	this->vertices.push_back(nxt_bottom_vertex);

	this->vertex_indices.push_back(vertices.size() - 1);
	this->vertex_indices.push_back(vertices.size() - 4);
	this->vertex_indices.push_back(vertices.size() - 3);
			
	this->vertex_indices.push_back(vertices.size() - 1);
	this->vertex_indices.push_back(vertices.size() - 2);
	this->vertex_indices.push_back(vertices.size() - 4);

	//wall 3
	x = width/2.0f;
	y = height;
	z = width / 2.0f;
	
	location = vec4(x, y, z, 1.0f);
	cur_top_vertex.position = vec3(m * location);
	cur_top_vertex.color = color2;
	cur_top_vertex.normal = vec3(0.0f, 0.0f, -1.0f);

	x = -width/2.0f;
	location = vec4(x, y, z, 1.0f);
	nxt_top_vertex.position = vec3(m * location);
	nxt_top_vertex.color = color2;
	nxt_top_vertex.normal = vec3(0.0f, 0.0f, -1.0f);

	y = 0.0f;
	location = vec4(x, y, z, 1.0f);
	nxt_bottom_vertex.position = vec3(m * location);
	nxt_bottom_vertex.color = color2;
	nxt_bottom_vertex.normal = vec3(0.0f, 0.0f, -1.0f);

	x = width/2.0f;
	location = vec4(x, y, z, 1.0f);
	cur_bottom_vertex.position = vec3(m * location);
	cur_bottom_vertex.color = color2;
	cur_bottom_vertex.normal = vec3(0.0f, 0.0f, -1.0f);

	this->vertices.push_back(cur_top_vertex);
	this->vertices.push_back(cur_bottom_vertex);
	this->vertices.push_back(nxt_top_vertex);
	this->vertices.push_back(nxt_bottom_vertex);

	this->vertex_indices.push_back(vertices.size() - 1);
	this->vertex_indices.push_back(vertices.size() - 4);
	this->vertex_indices.push_back(vertices.size() - 3);
			
	this->vertex_indices.push_back(vertices.size() - 1);
	this->vertex_indices.push_back(vertices.size() - 2);
	this->vertex_indices.push_back(vertices.size() - 4);

	//wall 4
	x = width/2.0f;
	y = height;
	z = -width/2.0f;
	
	location = vec4(x, y, z, 1.0f);
	cur_top_vertex.position = vec3(m * location);
	cur_top_vertex.color = color2;
	cur_top_vertex.normal = vec3(-1.0f, 0.0f, 0.0f);

	z = width/2.0f;
	location = vec4(x, y, z, 1.0f);
	nxt_top_vertex.position = vec3(m * location);
	nxt_top_vertex.color = color2;
	nxt_top_vertex.normal = vec3(-1.0f, 0.0f, 0.0f);

	y = 0.0f;
	location = vec4(x, y, z, 1.0f);
	nxt_bottom_vertex.position = vec3(m * location);
	nxt_bottom_vertex.color = color2;
	nxt_bottom_vertex.normal = vec3(-1.0f, 0.0f, 0.0f);

	z = -width/2.0f;
	location = vec4(x, y, z, 1.0f);
	cur_bottom_vertex.position = vec3(m * location);
	cur_bottom_vertex.color = color2;
	cur_bottom_vertex.normal = vec3(-1.0f, 0.0f, 0.0f);

	this->vertices.push_back(cur_top_vertex);
	this->vertices.push_back(cur_bottom_vertex);
	this->vertices.push_back(nxt_top_vertex);
	this->vertices.push_back(nxt_bottom_vertex);

	this->vertex_indices.push_back(vertices.size() - 1);
	this->vertex_indices.push_back(vertices.size() - 4);
	this->vertex_indices.push_back(vertices.size() - 3);
			
	this->vertex_indices.push_back(vertices.size() - 1);
	this->vertex_indices.push_back(vertices.size() - 2);
	this->vertex_indices.push_back(vertices.size() - 4);
	
	//top
	x = -width/2.0f;
	y = height;
	z = -width/2.0f;
	
	location = vec4(x, y, z, 1.0f);
	cur_top_vertex.position = vec3(m * location);
	cur_top_vertex.color = color2;
	cur_top_vertex.normal = vec3(0.0f, 1.0f, 0.0f);

	x = width/2.0f;
	location = vec4(x, y, z, 1.0f);
	nxt_top_vertex.position = vec3(m * location);
	nxt_top_vertex.color = color2;
	nxt_top_vertex.normal = vec3(0.0f, 1.0f, 0.0f);

	z = width/2.0f;
	location = vec4(x, y, z, 1.0f);
	nxt_bottom_vertex.position = vec3(m * location);
	nxt_bottom_vertex.color = color2;
	nxt_bottom_vertex.normal = vec3(0.0, 1.0f, 0.0f);

	x = -width/2.0f;
	location = vec4(x, y, z, 1.0f);
	cur_bottom_vertex.position = vec3(m * location);
	cur_bottom_vertex.color = color2;
	cur_bottom_vertex.normal = vec3(0.0, 1.0f, 0.0f);

	this->vertices.push_back(cur_top_vertex);
	this->vertices.push_back(cur_bottom_vertex);
	this->vertices.push_back(nxt_top_vertex);
	this->vertices.push_back(nxt_bottom_vertex);

	this->vertex_indices.push_back(vertices.size() - 1);
	this->vertex_indices.push_back(vertices.size() - 4);
	this->vertex_indices.push_back(vertices.size() - 3);
			
	this->vertex_indices.push_back(vertices.size() - 1);
	this->vertex_indices.push_back(vertices.size() - 2);
	this->vertex_indices.push_back(vertices.size() - 4);

	if (!this->PostGLInitialize(&this->vertex_array_handle, &this->vertex_coordinate_handle, this->vertices.size() * sizeof(VertexAttributesPCN), &this->vertices[0]))
		return false;

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexAttributesPCN), (GLvoid *) 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexAttributesPCN), (GLvoid *) (sizeof(vec3) * 2));	// Note offset - legacy of older code
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertexAttributesPCN), (GLvoid *) (sizeof(vec3) * 1));	// Same
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	if (this->normal_vertices.size() > 0)
	{
		if (!this->PostGLInitialize(&this->normal_array_handle, &this->normal_coordinate_handle, this->normal_vertices.size() * sizeof(VertexAttributesP), &this->normal_vertices[0]))
			return false;

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexAttributesP), (GLvoid *) 0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	if (shader == 0)
	{
		if (!this->shader.Initialize("phong_shader.vert", "phong_shader.frag"))
			return false;
	}
	if(shader == 1)
	{
		if (!this->shader.Initialize("blue_shader.vert", "blue_shader.frag"))
			return false;
	}
	/*
	if(shader == 2)
	{
		if(!this->adsShader.Initialize("light.vert", "light.frag"))
			return false;
		//if (!this->shader.Initialize("flat_shader.vert", "flat_shader.frag"))
			//return false;
	}
	if(shader == 3)
	{
		if (!this->adsShader.Initialize("flat_shader.vert", "flat_shader.frag"))
			return false;
	}

	if (!this->solid_color.Initialize("solid_shader.vert", "solid_shader.frag"))
			return false;
*/
	if (this->GLReturnedError("Background::Initialize - on exit"))
		return false;


	return true;
}

void Obstacle::TakeDown()
{
	this->vertices.clear();
	this->shader.TakeDown();
	this->adsShader.TakeDown();
	this->solid_color.TakeDown();
	super::TakeDown();
}

void Obstacle::Draw(const ivec2 & size)
{
	assert(false);
}

void Obstacle::Draw(const mat4 & projection, mat4 modelview, const ivec2 & size, const float time)
{
	if (this->GLReturnedError("Top::Draw - on entry"))
		return;

	glEnable(GL_DEPTH_TEST);

	mat4 mvp = projection * modelview;
	mat3 nm = inverse(transpose(mat3(modelview)));

	shader.Use();
	shader.CommonSetup(time, value_ptr(size), value_ptr(projection), value_ptr(modelview), value_ptr(mvp), value_ptr(nm));

/*	if(shade == 2)
	{
		adsShader.Use();
		adsShader.CommonSetup(time, value_ptr(size), value_ptr(projection), value_ptr(modelview), value_ptr(mvp), value_ptr(nm));

		//adsShader.SetLight(glm::vec4(0.0f, 0.0f, 2.0f, 1.0f), glm::vec3(0.2f), glm::vec3(0.7f), vec3(0.7f));
		//adsShader.SetMaterial(vec3(0.0f, 0.0f, 0.0f), vec3(0.588235f, 0.670588f, 0.729412f), vec3(0.9f, 0.9f, 0.9f), 96.0f);
		adsShader.SetLight(glm::vec4(0.0f, 0.0f, 2.0f, 1.0f), glm::vec3(0.2f), glm::vec3(0.7f), vec3(0.7f));
		adsShader.SetMaterial(vec3(0.24725f, 0.21995f, 0.0745f), vec3(0.75164f, 0.60648f, 0.22648f), vec3(0.628281f, 0.555802f, 0.366065f), 51.2f);
	}
	if(shade == 3)
	{
		adsShader.Use();
		adsShader.CommonSetup(time, value_ptr(size), value_ptr(projection), value_ptr(modelview), value_ptr(mvp), value_ptr(nm));
		adsShader.SetLight(glm::vec4(0.0f, 0.0f, 2.0f, 1.0f), glm::vec3(0.2f), glm::vec3(0.7f), vec3(0.7f));
		adsShader.SetMaterial(vec3(0.24725f, 0.21995f, 0.0745f), vec3(0.75164f, 0.60648f, 0.22648f), vec3(0.628281f, 0.555802f, 0.366065f), 51.2f);
	}*/
	glBindVertexArray(this->vertex_array_handle);
	glDrawElements(GL_TRIANGLES , this->vertex_indices.size(), GL_UNSIGNED_INT , &this->vertex_indices[0]);
	glBindVertexArray(0);
	glUseProgram(0);

	if (this->draw_normals)
	{
		this->solid_color.Use();
		this->solid_color.CommonSetup(time, value_ptr(size), value_ptr(projection), value_ptr(modelview), value_ptr(mvp), value_ptr(nm));
		glBindVertexArray(this->normal_array_handle);
		glDrawElements(GL_LINES , this->normal_indices.size(), GL_UNSIGNED_INT , &this->normal_indices[0]);
		glBindVertexArray(0);
		glUseProgram(0);
	}

	if (this->GLReturnedError("Top::Draw - on exit"))
		return;

	//time -= 1E3;
}

