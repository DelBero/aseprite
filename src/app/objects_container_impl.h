/* ASEPRITE
 * Copyright (C) 2001-2013  David Capello
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef APP_DOC_OBJECTS_CONTAINER_H_INCLUDED
#define APP_DOC_OBJECTS_CONTAINER_H_INCLUDED

#include "undo/objects_container.h"

#include <map>

namespace app {

  class ObjectsContainerImpl : public undo::ObjectsContainer {
  public:
    ObjectsContainerImpl();
    ~ObjectsContainerImpl();

    // ObjectsContainer Implementation

    undo::ObjectId addObject(void* object);
    void insertObject(undo::ObjectId id, void* object);
    void removeObject(undo::ObjectId id);
    void* getObject(undo::ObjectId id);

  private:
    undo::ObjectId m_idCounter;
    std::map<undo::ObjectId, void*> m_idToPtr;
    std::map<void*, undo::ObjectId> m_ptrToId;
  };

} // namespace app

#endif