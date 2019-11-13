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
Vertex** read_file(FILE*);

#endif /* !__PLY_H__ */
