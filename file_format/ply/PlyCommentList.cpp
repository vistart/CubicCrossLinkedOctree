/*
 *  _   __ __ _____ _____ ___  ____  _____
 * | | / // // ___//_  _//   ||  __||_   _|
 * | |/ // /(__  )  / / / /| || |     | |
 * |___//_//____/  /_/ /_/ |_||_|     |_|
 * @link https://vistart.me/
 * @copyright Copyright (c) 2019 - 2020 vistart
 * @license https://vistart.me/license/
*/
#ifndef __PLY_COMMENT_LIST_H__
#include "PlyCommentList.h"
#endif

#ifdef __PLY_COMMENT_LIST_H__
using namespace std;
bool PlyCommentList::add(string const& comment) const
{
    this->comments->emplace_back(comment);
    return true;
}

shared_ptr<vector<string>> PlyCommentList::getComments() const
{
    return this->comments;
}

PlyCommentList& PlyCommentList::operator<<(string const& comment)
{
    if (this->add(comment)) {

    }
    return *this;
}

PlyCommentList::PlyCommentList()
{
    /*
     * Initialize it before using.
     */
    this->comments = make_unique<vector<string>>();
}

PlyCommentList::~PlyCommentList()
{
    this->comments = nullptr;
}
#endif
