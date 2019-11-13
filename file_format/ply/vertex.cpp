#include "ply.h"
#include <cstdlib>
#include "vertex.h"
#include <iostream>
#include <iomanip>

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


/******************************************************************************
Negate the vertex normals.
******************************************************************************/

void negate_normals()
{
	int i;

	for (i = 0; i < nverts; i++) {
		if (has_nx) vlist[i]->nx *= -1;
		if (has_ny) vlist[i]->ny *= -1;
		if (has_nz) vlist[i]->nz *= -1;
	}
}

/******************************************************************************
Read in the PLY file from standard in.
******************************************************************************/

Vertex** read_file(FILE* in_ply_path)
{
	int i, j;
	int elem_count;
	char* elem_name;

	/*** Read in the original PLY object ***/

	in_ply = read_ply(in_ply_path);

	/* examine each element type that is in the file (vertex, face) */

	for (i = 0; i < in_ply->num_elem_types; i++) {

		/* prepare to read the i'th list of elements */
		elem_name = setup_element_read_ply(in_ply, i, &elem_count);

		if (equal_strings("vertex", elem_name)) {

			/* create a vertex list to hold all the vertices */
			vlist = (Vertex**)malloc(sizeof(Vertex*) * elem_count);
			nverts = elem_count;

			/* set up for getting vertex elements */
			/* (we want x,y,z) */

			setup_property_ply(in_ply, &vert_props[0]);
			setup_property_ply(in_ply, &vert_props[1]);
			setup_property_ply(in_ply, &vert_props[2]);

			/* we also want normal information if it is there (nx,ny,nz) */

			for (j = 0; j < in_ply->elems[i]->nprops; j++) {
				PlyProperty* prop;
				prop = in_ply->elems[i]->props[j];
				if (equal_strings("nx", prop->name)) {
					setup_property_ply(in_ply, &vert_props[3]);
					has_nx = 1;
				}
				if (equal_strings("ny", prop->name)) {
					setup_property_ply(in_ply, &vert_props[4]);
					has_ny = 1;
				}
				if (equal_strings("nz", prop->name)) {
					setup_property_ply(in_ply, &vert_props[5]);
					has_nz = 1;
				}
			}

			/* also grab anything else that we don't need to know about */

			vert_other = get_other_properties_ply(in_ply,
				offsetof(Vertex, other_props));

			/* grab the vertex elements and store them in our list */

			for (j = 0; j < elem_count; j++) {
				vlist[j] = (Vertex*)malloc(sizeof(Vertex));
				get_element_ply(in_ply, (void*)vlist[j]);
			}
		}
	}
	return vlist;
}