#pragma once
#include <string>
#include <cstdio>
#include <ffgl/FFGLPluginSDK.h>
#include <ffglex/FFGLShader.h>
#include <ffglex/FFGLScreenQuad.h>
//#include <FFGLSDK.h>

class Test360 : public CFFGLPlugin
{
public:
	Test360();
	~Test360();

	//CFFGLPlugin
	FFResult InitGL( const FFGLViewportStruct* vp ) override;
	FFResult ProcessOpenGL( ProcessOpenGLStruct* pGL ) override;
	FFResult DeInitGL() override;

	FFResult SetFloatParameter( unsigned int dwIndex, float value ) override;

	float GetFloatParameter( unsigned int index ) override;
    char* GetParameterDisplay(unsigned int index) override;

private:
    float pitch;
    float yaw;
    float roll;

	ffglex::FFGLShader shader;  //!< Utility to help us compile and link some shaders into a program.
	ffglex::FFGLScreenQuad quad;//!< Utility to help us render a full screen quad.
    GLint maxUVLocation;
    GLint fieldOfViewLocation;
};
