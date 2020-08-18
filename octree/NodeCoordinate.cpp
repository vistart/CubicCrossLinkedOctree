/*
 *  _   __ __ _____ _____ ___  ____  _____
 * | | / // // ___//_  _//   ||  __||_   _|
 * | |/ // /(__  )  / / / /| || |     | |
 * |___//_//____/  /_/ /_/ |_||_|     |_|
 * @link https://vistart.me/
 * @copyright Copyright (c) 2019 - 2020 vistart
 * @license https://vistart.me/license/
*/
#ifndef __NODE_COORDINATE_H__
#include "NodeCoordinate.h"
#endif

#ifdef __NODE_COORDINATE_H__

bool NodeCoordinate::operator==(NodeCoordinate const& node_coordinate) const
{
    return (X == node_coordinate.X && Y == node_coordinate.Y && Z == node_coordinate.Z && depth == node_coordinate.depth);
}
#endif