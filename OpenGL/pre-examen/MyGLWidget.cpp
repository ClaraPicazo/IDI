#include <GL/glew.h>
#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget (QGLFormat &f, QWidget* parent) : QGLWidget(f, parent)
{
  setFocusPolicy(Qt::ClickFocus);  // per rebre events de teclat
  xClick = yClick = 0;
  angleY = 0.0;
  anglerot = 0.0;
  DoingInteractive = NONE;
  radiEsc = sqrt(3);
  posFocus = glm::vec3(0, 0, -2*radiEsc);
  FOV = FOVinicial = M_PI/3.0;
  ra = 1.0;
  trasllada = 0.0;
}

void MyGLWidget::initializeGL ()
{
  // glew és necessari per cridar funcions de les darreres versions d'OpenGL
  glewExperimental = GL_TRUE;
  glewInit(); 
  glGetError();  // Reinicia la variable d'error d'OpenGL

  glClearColor (0.5, 0.7, 1.0, 1.0);  // defineix color de fons (d'esborrat)
  glEnable(GL_DEPTH_TEST);
  carregaShaders ();
  createBuffers ();
  projectTransform ();
  viewTransform ();
}

void MyGLWidget::paintGL ()
{
  // Esborrem el frame-buffer i el depth-buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  /*-------PINTEM EL TERRA------------*/

  // Activem el VAO per a pintar el terra 
  glBindVertexArray (VAO_Terra);

  modelTransformTerra ();

  // pintem
  glDrawArrays(GL_TRIANGLES, 0, 12);

  /*---------------------------------------*/

  // Activem el VAO per a pintar el Patricio
  glBindVertexArray (VAO_Patr);


  /*--------PINTEM EL PRIMER PATRICIO --------*/

  modelTransformPatricio();

  // Pintem l'escena
  glDrawArrays(GL_TRIANGLES, 0, patr.faces().size()*3);

  /*----------PINTEM EL SEGON PATRICIO---------*/

  modelTransformPatricio2();

  // Pintem l'escena
  glDrawArrays(GL_TRIANGLES, 0, patr.faces().size()*3);
  

  /*----------PINTEM EL mini PATRICIO---------*/

  modelTransformMiniPat();

  // Pintem l'escena
  glDrawArrays(GL_TRIANGLES, 0, patr.faces().size()*3);


  /*----------PINTEM la vaca---------*/

  // Activem el VAO per a pintar la vaca
  glBindVertexArray (VAO_cow);

  modelTransformVaca();

  // Pintem l'escena
  glDrawArrays(GL_TRIANGLES, 0, cow.faces().size()*3);

  /*--------------------------------------------*/
  viewTransform();

  glBindVertexArray(0);
}

void MyGLWidget::resizeGL (int w, int h)
{
    ra = (double)w/(double)h;
    if (ra < 1){
        FOV = 2*atan(tan(FOVinicial/2)/ra);
    }
    else FOV = FOVinicial;

    projectTransform();

    glViewport (0, 0, w, h);
}

void MyGLWidget::createBuffers ()
{
  // Carreguem el model de l'OBJ - Atenció! Abans de crear els buffers!
  //patr.load("/assig/idi/models/Patricio.obj");
  patr.load("./models/Patricio.obj");

  // Calculem la capsa contenidora del model
  calculaCapsaPatricio();
  
  // Creació del Vertex Array Object del Patricio
  glGenVertexArrays(1, &VAO_Patr);
  glBindVertexArray(VAO_Patr);

  // Creació dels buffers del model patr
  // Buffer de posicions
  glGenBuffers(1, &VBO_PatrPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_PatrPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*patr.faces().size()*3*3, patr.VBO_vertices(), GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  // Buffer de normals
  glGenBuffers(1, &VBO_PatrNorm);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_PatrNorm);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*patr.faces().size()*3*3, patr.VBO_normals(), GL_STATIC_DRAW);

  glVertexAttribPointer(normalLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(normalLoc);

  // En lloc del color, ara passem tots els paràmetres dels materials
  // Buffer de component ambient
  glGenBuffers(1, &VBO_PatrMatamb);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_PatrMatamb);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*patr.faces().size()*3*3, patr.VBO_matamb(), GL_STATIC_DRAW);

  glVertexAttribPointer(matambLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matambLoc);

  // Buffer de component difusa
  glGenBuffers(1, &VBO_PatrMatdiff);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_PatrMatdiff);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*patr.faces().size()*3*3, patr.VBO_matdiff(), GL_STATIC_DRAW);

  glVertexAttribPointer(matdiffLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matdiffLoc);

  // Buffer de component especular
  glGenBuffers(1, &VBO_PatrMatspec);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_PatrMatspec);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*patr.faces().size()*3*3, patr.VBO_matspec(), GL_STATIC_DRAW);

  glVertexAttribPointer(matspecLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matspecLoc);

  // Buffer de component shininness
  glGenBuffers(1, &VBO_PatrMatshin);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_PatrMatshin);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*patr.faces().size()*3, patr.VBO_matshin(), GL_STATIC_DRAW);

  glVertexAttribPointer(matshinLoc, 1, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matshinLoc);

  /*------------------------------importem el model vaca --------------------*/

  // Carreguem el model de l'OBJ - Atenció! Abans de crear els buffers!
  //patr.load("/assig/idi/models/Patricio.obj");
  cow.load("./models/cow.obj");

  // Calculem la capsa contenidora del model
  calculaCapsaVaca ();

  // Creació del Vertex Array Object del Patricio
  glGenVertexArrays(1, &VAO_cow);
  glBindVertexArray(VAO_cow);

  // Creació dels buffers del model patr
  // Buffer de posicions
  glGenBuffers(1, &VBO_cowPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_cowPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*cow.faces().size()*3*3, cow.VBO_vertices(), GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  // Buffer de normals
  glGenBuffers(1, &VBO_cowNorm);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_cowNorm);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*cow.faces().size()*3*3, cow.VBO_normals(), GL_STATIC_DRAW);

  glVertexAttribPointer(normalLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(normalLoc);

  // En lloc del color, ara passem tots els paràmetres dels materials
  // Buffer de component ambient
  glGenBuffers(1, &VBO_cowMatamb);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_cowMatamb);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*cow.faces().size()*3*3, cow.VBO_matamb(), GL_STATIC_DRAW);

  glVertexAttribPointer(matambLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matambLoc);

  // Buffer de component difusa
  glGenBuffers(1, &VBO_cowMatdiff);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_cowMatdiff);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*cow.faces().size()*3*3, cow.VBO_matdiff(), GL_STATIC_DRAW);

  glVertexAttribPointer(matdiffLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matdiffLoc);

  // Buffer de component especular
  glGenBuffers(1, &VBO_cowMatspec);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_cowMatspec);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*cow.faces().size()*3*3, cow.VBO_matspec(), GL_STATIC_DRAW);

  glVertexAttribPointer(matspecLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matspecLoc);

  // Buffer de component shininness
  glGenBuffers(1, &VBO_cowMatshin);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_cowMatshin);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*cow.faces().size()*3, cow.VBO_matshin(), GL_STATIC_DRAW);

  glVertexAttribPointer(matshinLoc, 1, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matshinLoc);

  /*------------------------------------------------------------------------*/

  // Dades del terra
  // VBO amb la posició dels vèrtexs
  glm::vec3 posterra[12] = {
	glm::vec3(-1.0, -1.0, 1.0),
	glm::vec3(1.0, -1.0, 1.0),
	glm::vec3(-1.0, -1.0, -1.0),
	glm::vec3(-1.0, -1.0, -1.0),
	glm::vec3(1.0, -1.0, 1.0),
	glm::vec3(1.0, -1.0, -1.0),
	glm::vec3(-1.0, -1.0, -1.0),
	glm::vec3(1.0, -1.0, -1.0),
	glm::vec3(-1.0, 1.0, -1.0),
	glm::vec3(-1.0, 1.0, -1.0),
	glm::vec3(1.0, -1.0, -1.0),
	glm::vec3(1.0, 1.0, -1.0)
  }; 

  // VBO amb la normal de cada vèrtex
  glm::vec3 norm1 (0,1,0);
  glm::vec3 norm2 (0,0,1);
  glm::vec3 normterra[12] = {
	norm1, norm1, norm1, norm1, norm1, norm1, // la normal (0,1,0) per als primers dos triangles
	norm2, norm2, norm2, norm2, norm2, norm2  // la normal (0,0,1) per als dos últims triangles
  };

  // Definim el material del terra
  glm::vec3 amb(0.2,0,0.2);
  glm::vec3 diff(0.8,0,0.8);
  glm::vec3 spec(0,0,0);
  float shin = 100;

  // Fem que aquest material afecti a tots els vèrtexs per igual
  glm::vec3 matambterra[12] = {
	amb, amb, amb, amb, amb, amb, amb, amb, amb, amb, amb, amb
  };
  glm::vec3 matdiffterra[12] = {
	diff, diff, diff, diff, diff, diff, diff, diff, diff, diff, diff, diff
  };
  glm::vec3 matspecterra[12] = {
	spec, spec, spec, spec, spec, spec, spec, spec, spec, spec, spec, spec
  };
  float matshinterra[12] = {
	shin, shin, shin, shin, shin, shin, shin, shin, shin, shin, shin, shin
  };

// Creació del Vertex Array Object del terra
  glGenVertexArrays(1, &VAO_Terra);
  glBindVertexArray(VAO_Terra);

  glGenBuffers(1, &VBO_TerraPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(posterra), posterra, GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glGenBuffers(1, &VBO_TerraNorm);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraNorm);
  glBufferData(GL_ARRAY_BUFFER, sizeof(normterra), normterra, GL_STATIC_DRAW);

  // Activem l'atribut normalLoc
  glVertexAttribPointer(normalLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(normalLoc);

  // En lloc del color, ara passem tots els paràmetres dels materials
  // Buffer de component ambient
  glGenBuffers(1, &VBO_TerraMatamb);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraMatamb);
  glBufferData(GL_ARRAY_BUFFER, sizeof(matambterra), matambterra, GL_STATIC_DRAW);

  glVertexAttribPointer(matambLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matambLoc);

  // Buffer de component difusa
  glGenBuffers(1, &VBO_TerraMatdiff);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraMatdiff);
  glBufferData(GL_ARRAY_BUFFER, sizeof(matdiffterra), matdiffterra, GL_STATIC_DRAW);

  glVertexAttribPointer(matdiffLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matdiffLoc);

  // Buffer de component especular
  glGenBuffers(1, &VBO_TerraMatspec);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraMatspec);
  glBufferData(GL_ARRAY_BUFFER, sizeof(matspecterra), matspecterra, GL_STATIC_DRAW);

  glVertexAttribPointer(matspecLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matspecLoc);

  // Buffer de component shininness
  glGenBuffers(1, &VBO_TerraMatshin);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraMatshin);
  glBufferData(GL_ARRAY_BUFFER, sizeof(matshinterra), matshinterra, GL_STATIC_DRAW);

  glVertexAttribPointer(matshinLoc, 1, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(matshinLoc);

  glBindVertexArray(0);
}

void MyGLWidget::carregaShaders ()
{
  // Creem els shaders per al fragment i vertex shader
  QGLShader fs(QGLShader::Fragment, this);
  QGLShader vs(QGLShader::Vertex, this);
  // Carreguem el codi dels fitxers i els compilem 
  fs.compileSourceFile("./shaders/fragshad.frag");
  vs.compileSourceFile("./shaders/vertshad.vert");

  // Creem el program
  program = new QGLShaderProgram(this);
  // Li afegim els shaders corresponents
  program->addShader(&fs);
  program->addShader(&vs);

  // Linkem el program
  program->link();

  // Indiquem que aquest és el program que volem usar
  program->bind();

  // Obtenim identificador per a l'atribut “vertex” del vertex shader
  vertexLoc = glGetAttribLocation (program->programId(), "vertex");
  // Obtenim identificador per a l'atribut “normal” del vertex shader
  normalLoc = glGetAttribLocation (program->programId(), "normal");
  // Obtenim identificador per a l'atribut “matamb” del vertex shader
  matambLoc = glGetAttribLocation (program->programId(), "matamb");
  // Obtenim identificador per a l'atribut “matdiff” del vertex shader
  matdiffLoc = glGetAttribLocation (program->programId(), "matdiff");
  // Obtenim identificador per a l'atribut “matspec” del vertex shader
  matspecLoc = glGetAttribLocation (program->programId(), "matspec");
  // Obtenim identificador per a l'atribut “matshin” del vertex shader
  matshinLoc = glGetAttribLocation (program->programId(), "matshin");

  // Demanem identificadors per als uniforms del vertex shader
  transLoc = glGetUniformLocation (program->programId(), "TG");
  projLoc = glGetUniformLocation (program->programId(), "proj");
  viewLoc = glGetUniformLocation (program->programId(), "view");
  posFocusLoc = glGetUniformLocation (program->programId(), "posFocus");
}

void MyGLWidget::carregaLlum(){
    glUniform3fv(posFocusLoc,1,&posFocus[0]);
}

void MyGLWidget::modelTransformPatricio ()
{
  glm::mat4 TG;  // Matriu de transformació
  TG = glm::translate(TG,glm::vec3(trasllada,0,0));
  TG = glm::scale(TG, glm::vec3(patricio.escala));
  TG = glm::translate(TG, -patricio.centreCapsa());
  
  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformPatricio2 ()
{
  glm::mat4 TG;  // Matriu de transformació
  TG = glm::translate(TG,glm::vec3(0,patricio.height,0));
  TG = glm::rotate(TG,(float) (M_PI),glm::vec3(0,0,1));
  TG = glm::scale(TG, glm::vec3(patricio.escala));
  TG = glm::translate(TG, -patricio.centreCapsa());

  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformMiniPat ()
{
  glm::mat4 TG;  // Matriu de transformació
  TG = glm::translate(TG,glm::vec3(1,-0.5,0));
  TG = glm::rotate(TG,anglerot,glm::vec3(0,1,0));
  TG = glm::scale(TG, glm::vec3(minipat.escala));
  TG = glm::translate(TG, -patricio.centreCapsa());

  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformVaca ()
{
  glm::mat4 TG;  // Matriu de transformació
  TG = glm::translate(TG,glm::vec3(1,-1,0));
  TG = glm::rotate(TG,anglerot,glm::vec3(0,1,0));
  TG = glm::rotate(TG,(float) -(M_PI/2),glm::vec3(0,0,1));
  TG = glm::rotate(TG,(float) -(M_PI/2),glm::vec3(0,1,0));
  TG = glm::scale(TG, glm::vec3(vaca.escala));
  TG = glm::translate(TG, -vaca.centreCapsa());

  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}
void MyGLWidget::modelTransformTerra ()
{
  glm::mat4 TG;  // Matriu de transformació
  TG = glm::mat4(1.f);
  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::projectTransform ()
{
  //sempre mantenim la aspect ratio de la pantalla per evitar deformacions
  glm::mat4 Proj;  // Matriu de projecció
  Proj = glm::perspective(FOV, ra,Znear,Zfar);

  glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);
}

void MyGLWidget::viewTransform ()
{
  glm::mat4 View;  // Matriu de posició i orientació
  View = glm::lookAt(glm::vec3(-1,1,-1),glm::vec3(trasllada,0,0),glm::vec3(0,1,0));
  //View = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, -2*radiEsc));
  View = glm::rotate(View, -angleY, glm::vec3(0, 1, 0));

  glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::calculaCapsaPatricio ()
{
  // Càlcul capsa contenidora i valors transformacions inicials

  patricio.minx = patricio.maxx = patr.vertices()[0];
  patricio.miny = patricio.maxy = patr.vertices()[1];
  patricio.minz = patricio.maxz = patr.vertices()[2];
  for (unsigned int i = 3; i < patr.vertices().size(); i+=3)
  {
    if (patr.vertices()[i+0] < patricio.minx)
      patricio.minx = patr.vertices()[i+0];
    if (patr.vertices()[i+0] > patricio.maxx)
      patricio.maxx = patr.vertices()[i+0];
    if (patr.vertices()[i+1] < patricio.miny)
      patricio.miny = patr.vertices()[i+1];
    if (patr.vertices()[i+1] > patricio.maxy)
      patricio.maxy = patr.vertices()[i+1];
    if (patr.vertices()[i+2] < patricio.minz)
      patricio.minz = patr.vertices()[i+2];
    if (patr.vertices()[i+2] > patricio.maxz)
      patricio.maxz = patr.vertices()[i+2];
  }
  patricio.height = 2.0;
  minipat.height = 0.25;
  patricio.escala = patricio.height/(patricio.maxy-patricio.miny);
  minipat.escala = minipat.height/(patricio.maxy-patricio.miny);

  distancia = 2*patricio.radi()*patricio.escala;
  Znear = distancia - patricio.radi()*patricio.escala;
  Zfar = distancia + patricio.radi()*patricio.escala;

}

void MyGLWidget::calculaCapsaVaca ()
{
  // Càlcul capsa contenidora i valors transformacions inicials

  vaca.minx = vaca.maxx = cow.vertices()[0];
  vaca.miny = vaca.maxy = cow.vertices()[1];
  vaca.minz = vaca.maxz = cow.vertices()[2];
  for (unsigned int i = 3; i < cow.vertices().size(); i+=3)
  {
    if (cow.vertices()[i+0] < vaca.minx)
      vaca.minx = cow.vertices()[i+0];
    if (cow.vertices()[i+0] > vaca.maxx)
      vaca.maxx = cow.vertices()[i+0];
    if (cow.vertices()[i+1] < vaca.miny)
      vaca.miny = cow.vertices()[i+1];
    if (cow.vertices()[i+1] > vaca.maxy)
      vaca.maxy = cow.vertices()[i+1];
    if (cow.vertices()[i+2] < vaca.minz)
      vaca.minz = cow.vertices()[i+2];
    if (cow.vertices()[i+2] > vaca.maxz)
      vaca.maxz = cow.vertices()[i+2];
  }
  vaca.height = 0.5;
  vaca.escala = vaca.height/(vaca.maxy-vaca.miny);

}

void MyGLWidget::keyPressEvent (QKeyEvent *e)
{
  switch (e->key())
  {
    case Qt::Key_Escape:
        exit(0);
    case Qt::Key_R:
        anglerot += M_PI/6.0;
        break;
    case Qt::Key_L:
        trasllada += 0.02;
        break;
    case Qt::Key_K:
        trasllada -= 0.02;
        break;

    default: e->ignore(); break;
  }
  updateGL();
}

void MyGLWidget::mousePressEvent (QMouseEvent *e)
{
  xClick = e->x();
  yClick = e->y();

  if (e->button() & Qt::LeftButton &&
      ! (e->modifiers() & (Qt::ShiftModifier|Qt::AltModifier|Qt::ControlModifier)))
  {
    DoingInteractive = ROTATE;
  }
}

void MyGLWidget::mouseReleaseEvent( QMouseEvent *)
{
  DoingInteractive = NONE;
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e)
{
  // Aqui cal que es calculi i s'apliqui la rotacio o el zoom com s'escaigui...
  if (DoingInteractive == ROTATE)
  {
    // Fem la rotació
    angleY += (e->x() - xClick) * M_PI / 180.0;
    viewTransform ();
  }

  xClick = e->x();
  yClick = e->y();

  updateGL ();
}


