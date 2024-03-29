#include <stdio.h>
#include "shaderManager.h"
#include "Utils.h"

shaderManager* shaderManager::manager;

shaderManager* shaderManager::get(){
	if (manager == NULL) {
		manager = new shaderManager(NULL);
	}
	return manager;
};

shaderManager::shaderManager(abstractObject* parent) : abstractObject(parent) {
	//printf("Created shaderManager\n");
}

shaderManager::~shaderManager() {
	//printf("Unloaded shaderManager\n");
}

GLuint shaderManager::getShader(const char* vert, const char* frag, const char* geom){
// Unfinished code
	string shadername = string(vert).append("-").append(frag).append("-").append(geom);
	for (vector<string>::iterator name = names.begin();
                           name != names.end();
                           ++name) {
    	if (shadername.compare(*name) == 0) { //this shader already exists
    		//printf("Returning existing shader %s\n", shadername.c_str());
    		// delete shadername;
    		//get the distance between current position of name and beginnings
    		return shaders.at(name-names.begin()); 
    	}
    }
	//printf("Creating shaderprogram with %s, %s and %s.\n", vert, frag, geom);
	//create a new shaderprogram and attach the shaders
	GLuint shaderprogram, vertexshader, wireshader, fragmentshader;
	shaderprogram = glCreateProgram();
	
	// printf("Create vertex shader %s\n", vert);
	const GLchar *vertexsource = filetobuf(vert);
	vertexshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexshader, 1, (const GLchar**)&vertexsource, 0);
	glCompileShader(vertexshader);
	glAttachShader(shaderprogram, vertexshader);

	// printf("Create fragment shader %s\n", frag);
	const GLchar* fragmentsource = filetobuf(frag);
	fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentshader, 1, (const GLchar**)&fragmentsource, 0);
	glCompileShader(fragmentshader);
	glAttachShader(shaderprogram, fragmentshader);

 	// printf("Create geometry shader%s\n", geom);
	const GLchar* wiresource = filetobuf(geom);
	wireshader = glCreateShader(GL_GEOMETRY_SHADER);
	glShaderSource(wireshader, 1, (const GLchar**)&wiresource, 0);
	glCompileShader(wireshader);
	glAttachShader(shaderprogram, wireshader);
	
	//link the program
	glLinkProgram(shaderprogram);
	names.push_back( shadername );
	shaders.push_back(shaderprogram);


    char text[1000];
    int length;

    glGetProgramInfoLog(shaderprogram, 1000, &length, text);
    if(length>0)
        fprintf(stderr, "Validate Shader Program\n%s\n",text );

	glUseProgram(shaderprogram);

glBindAttribLocation(shaderprogram, 0, "in_Position");

	//printf("Added new shader: %s\tTotal stored: %d\n", names.back().c_str(), (int)(names.size()));
	return shaderprogram;
}