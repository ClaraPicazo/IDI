#include <GL/glew.h>
#include "MyGLWidget.h"
#include "glm/gtc/matrix_transform.hpp"
#include <QGLShader>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGLShaderProgram>

#include <iostream>

int varLoc;
int transLoc;
float scl;
glm::mat4 TG;

void MyGLWidget::keyPressEvent(QKeyEvent *e){
  switch(e->key()){
    case Qt::Key_Escape:
	exit(0);
	break;
    case Qt::Key_S:
      scl += 0.1;
      glUniform1f(varLoc,scl);
      updateGL();
      break;
    case Qt::Key_D:
      scl -= 0.1;
      glUniform1f(varLoc,scl);
      updateGL();
      break;
    case Qt::Key_L:
      TG = glm::translate(TG,glm::vec3(0.1,0,0));
      glUniformMatrix4fv(transLoc,1,GL_FALSE,&TG[0][0]);
      updateGL();
      break;
    case Qt::Key_K:
      TG = glm::translate(TG,glm::vec3(-0.1,0,0));
      glUniformMatrix4fv(transLoc,1,GL_FALSE,&TG[0][0]);
      updateGL();
      break;
    default: e->ignore();
  }
}


MyGLWidget::MyGLWidget (QGLFormat &f, QWidget* parent) : QGLWidget(f, parent)
{
  setFocusPolicy(Qt::ClickFocus);  // per rebre events de teclat
}

void MyGLWidget::initializeGL ()
{
  // glew és necessari per cridar funcions de les darreres versions d'OpenGL
  glewExperimental = GL_TRUE;
  glewInit(); 
  glGetError();  // Reinicia la variable d'error d'OpenGL

  glClearColor (0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  
  //afegim shaders
  QGLShader fs (QGLShader::Fragment,this);
  fs.compileSourceFile ("./fragshad.frag");
  QGLShader vs (QGLShader::Vertex,this);
  vs.compileSourceFile ("./vertshad.vert");
	
  
  QGLShaderProgram program(this);
  program.addShader(&fs);
  program.addShader(&vs);
  program.link();
  program.bind();
  
  //ubiquem l'uniform i li donem el  valor inicial d'escalat
  varLoc = glGetUniformLocation(program.programId(), "val");
  transLoc = glGetUniformLocation(program.programId(), "TG");
  scl = 0.5;
  glUniform1f(varLoc,scl);
  TG = glm::mat4(1.0);
  glUniformMatrix4fv(transLoc,1,GL_FALSE,&TG[0][0]);
  
  //creem els buffers
  createBuffers();
}

void MyGLWidget::paintGL ()
{
  glClear (GL_COLOR_BUFFER_BIT);  // Esborrem el frame-buffer

  // Activem l'Array a pintar 
  glBindVertexArray(VAO);
 
  // Pintem l'escena
  glDrawArrays(GL_TRIANGLES, 0, 3);
  
  // Desactivem el VAO
  glBindVertexArray(0);
}

void MyGLWidget::resizeGL (int w, int h)
{
  glViewport (0, 0, w, h);
}

void MyGLWidget::createBuffers ()
{
  glm::vec3 Vertices[3];  // Tres vèrtexs amb X, Y i Z
  Vertices[0] = glm::vec3(-1.0, -1.0, 0.0);
  Vertices[1] = glm::vec3(1.0, -1.0, 0.0);
  Vertices[2] = glm::vec3(0.0, 1.0, 0.0);
  
  // Creació del Vertex Array Object (VAO) que usarem per pintar
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  // Creació del buffer amb les dades dels vèrtexs
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
  
  // Activem l'atribut que farem servir per vèrtex (només el 0 en aquest cas)	
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);

  // Desactivem el VAO
  glBindVertexArray(0);
}

