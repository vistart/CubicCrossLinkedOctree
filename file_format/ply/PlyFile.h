/*
 *  _   __ __ _____ _____ ___  ____  _____
 * | | / // // ___//_  _//   ||  __||_   _|
 * | |/ // /(__  )  / / / /| || |     | |
 * |___//_//____/  /_/ /_/ |_||_|     |_|
 * @link https://vistart.me/
 * @copyright Copyright (c) 2019 - 2020 vistart
 * @license https://vistart.me/license/
*/
#pragma once

#ifndef __PLY_FILE_H__
#define __PLY_FILE_H__

#include "PlyFileEncoding.h"
#include "PlyVertexList.h"
#include "PlyFaceList.h"
#include "PlyEdgeList.h"
#include "PlyCommentList.h"
#include "PointCloud.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
 This class is used to describe the ply file.
 */
class PlyFile : public PointCloud<PlyVertexList, PlyVertex, PlyFile>
{
public:
#pragma region Constructor & Destructor
    explicit PlyFile(string);
    ~PlyFile();
#pragma endregion

#pragma region File Format
    string GetFileFormat();
#pragma endregion

#pragma region File Encoding
    shared_ptr<PlyFileEncoding> FileEncoding;
#pragma endregion

#pragma region Comment
    shared_ptr<PlyCommentList> CommentList;
#pragma endregion

#pragma region Vertex
    shared_ptr<PlyVertexList> GetPointList();
#pragma endregion

#pragma region Face
    shared_ptr<PlyFaceList> FaceList;
#pragma endregion

#pragma region Edge
    shared_ptr<PlyEdgeList> EdgeList;
#pragma endregion

    bool GetIsValid();

protected:
    /* The file currently being accessed. */
    fstream file;
    /* The filename currently being accessed. */
    string filename;
    /* Indicates whether the file was read correctly. */
    bool valid = false;
    /**
     Open the file.

     @param string the filename to be opened.
     @return bool true if the file was opened successfully.
     */
    bool open(string);
    /* Supported header tags */
    enum Tag { PLY, FORMAT, COMMENT, ELEMENT, PROPERTY, END_HEADER };
    /**
     Read from ply file.
     The file format only supports ply, and the encoding format can be ASCII
     and binary (both big and little endian).
     To use this method, you need to use "fstream" to represent an open file
     stream.

     @param fstream& the file to be read.
     @return bool true if the file was read successfully.
     */
    bool read(fstream&);
    /**
     * Read header from ply file.
     * This method resets the file pointer to the beginning because the file
     * header is at the beginning of the file.
     *
     * Note: It is not recommended to call this method directly unless you know
     * the consequences of doing so.
     *
     * @param fstream& the file to be read.
     * @return bool true if the file was read successfully.
     */
    bool read_header(fstream&);
    /**
     * This method starts at the position pointed to by the incoming file
     * stream parameter, and determines the amount of data to be read according
     *
     * Note: It is not recommended to call this method directly unless you know
     * the consequences of doing so. If you want to call this method separately,
     * you need to make sure that the file pointer points to the appropriate
     * location yourself.
     *
     * @param fstream& the file to be read.
     * @return bool true if the file was read successfully.
     */
    bool read_body(fstream&);

#pragma region File Format
    enum FileFormatType { FILE_FORMAT_PLY };
    int file_format = FILE_FORMAT_PLY;
    bool set_file_format(string);
#pragma endregion

#pragma region File Encoding
    bool read_file_encoding(string, fstream&);
#pragma endregion

#pragma region Comment
    /**
     * When the tag is "comment", everything after this tag in the current line is a comment.
     */
    bool read_comment(string, fstream&);
#pragma endregion

#pragma region Vertex
    /**
     * Read Vertex Name from ply file.
     * This method is called when the tag of a line is "vertex". Therefore, the
     * file pointer should point to the content after "vertex".
     *
     * @param fstream& the file to be read.
     * @return bool true if the file was read successfully.
     */
    bool read_element_vertex_names(fstream&);
    /**
     * Read Vertex Encoding from ply file.
     * This method is called before reading vertex to determine the specific
     * file encoding.
     *
     * @param PlyFileEncoding const& the file encoding.
     * @return bool true if the file was read successfully.
     */
    bool read_element_vertex_encoding(PlyFileEncoding const&);
    /**
     * Read Vertex from ply file.
     * You need to determine the file encoding and number of points before
     * calling this method.
     * This method determines the meaning of each property based on vertex_names.
     *
     * @param fstream& the file to be read.
     * @return bool true if the file was read successfully.
     */
    bool read_element_vertex(fstream&);
    shared_ptr<PlyVertexList> point_list;
#pragma endregion

#pragma region Face
    /**
     * Read Face Name from ply file.
     * This method is called when the tag of a line is "face". Therefore, the
     * file pointer should point to the content after "face".
     *
     * @param fstream& the file to be read.
     * @return bool true if the file was read successfully.
     */
    bool read_element_face_names(fstream&);
    /**
     * Read Face from ply file.
     * You need to determine the file encoding and number of points before
     * calling this method.
     * This method determines the meaning of each property based on face list.
     *
     * @param fstream& the file to be read.
     * @return bool true if the file was read successfully.
     * @TODO
     */
    bool read_element_face(fstream&);
#pragma endregion

#pragma region Edge
    /**
     * Read Edge Name from ply file.
     * This method is called when the tag of a line is "edge". Therefore, the
     * file pointer should point to the content after "edge".
     *
     * @param fstream& the file to be read.
     * @return bool true if the file was read successfully.
     */
    bool read_element_edge_names(fstream&);
    /**
     * Read Edge from ply file.
     * You need to determine the file encoding and number of points before
     * calling this method.
     * This method determines the meaning of each property based on edge list.
     *
     * @param fstream& the file to be read.
     * @return bool true if the file was read successfully.
     */
    bool read_element_edge(fstream&);
#pragma endregion

#pragma region User-Defined Elements
    bool read_element_user_defined_names(fstream&);
    /**
     * Read User-defined elements from ply file.
     * You need to determine the file encoding and number of points before
     * calling this method.
     * This method determines the meaning of each property based on user-defined list.
     *
     * @param fstream& the file to be read.
     * @return bool true if the file was read successfully.
     */
    bool read_element_user_defined(fstream&);
#pragma endregion
};

#endif