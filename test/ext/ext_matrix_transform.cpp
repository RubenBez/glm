#include <glm/ext/matrix_relational.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/vector_relational.hpp>
#include <glm/ext/vector_float4.hpp>
#include <glm/ext/vector_float3.hpp>

static int test_translate()
{
	int Error = 0;

	glm::mat4 const M(1.0f);
	glm::vec3 const V(1.0f);

	glm::mat4 const T = glm::translate(M, V);
	Error += glm::all(glm::equal(T[3], glm::vec4(1.0f), glm::epsilon<float>())) ? 0 : 1;

	return Error;
}

static int test_scale()
{
	int Error = 0;

	glm::mat4 const M(1.0f);
	glm::vec3 const V(2.0f);

	glm::mat4 const S = glm::scale(M, V);
	glm::mat4 const R = glm::mat4(
		glm::vec4(2, 0, 0, 0),
		glm::vec4(0, 2, 0, 0),
		glm::vec4(0, 0, 2, 0),
		glm::vec4(0, 0, 0, 1));
	Error += glm::all(glm::equal(S, R, glm::epsilon<float>())) ? 0 : 1;

	return Error;
}

int main()
{
	int Error = 0;

	Error += test_translate();
	Error += test_scale();

	return Error;
}