#pragma once

#ifndef __VERTEX_H__
#define __VERTEX_H__
#include "ply.h"
/* user's vertex and face definitions for a polygonal object */

typedef struct Vertex {
	float x, y, z;
	float nx, ny, nz;
	void* other_props;       /* other properties */
} Vertex;

char* elem_names[] = { /* list of the kinds of elements in the user's object */
  "vertex"
};

PlyProperty vert_props[] = { /* list of property information for a vertex */
  {"x", Float32, Float32, offsetof(Vertex,x), 0, 0, 0, 0},
  {"y", Float32, Float32, offsetof(Vertex,y), 0, 0, 0, 0},
  {"z", Float32, Float32, offsetof(Vertex,z), 0, 0, 0, 0},
  {"nx", Float32, Float32, offsetof(Vertex,nx), 0, 0, 0, 0},
  {"ny", Float32, Float32, offsetof(Vertex,ny), 0, 0, 0, 0},
  {"nz", Float32, Float32, offsetof(Vertex,nz), 0, 0, 0, 0},
};


/*** the PLY object ***/

static PlyFile* in_ply;
static int nverts;
static Vertex** vlist;
static PlyOtherProp* vert_other;

/* are normals in PLY file? */
static int has_nx = 0;
static int has_ny = 0;
static int has_nz = 0;

void negate_normals();
void read_file(FILE*);

#endif /* !__PLY_H__ */
