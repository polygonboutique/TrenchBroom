/*
 Copyright (C) 2010-2017 Kristian Duske

 This file is part of TrenchBroom.

 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#include "AssortNodesVisitor.h"

namespace TrenchBroom {
    namespace Model {
        const std::vector<Layer*>& CollectLayersStrategy::layers() const { return m_layers; }
        void CollectLayersStrategy::addLayer(TrenchBroom::Model::Layer* layer) { m_layers.push_back(layer); }

        const std::vector<Layer*> SkipLayersStrategy::m_layers{};

        const std::vector<Layer*>& SkipLayersStrategy::layers() const { return m_layers; }
        void SkipLayersStrategy::addLayer(TrenchBroom::Model::Layer* /* layer */) {}


        const std::vector<Group*>& CollectGroupsStrategy::groups() const { return m_groups; }
        void CollectGroupsStrategy::addGroup(Group* group) { m_groups.push_back(group); }

        const std::vector<Group*> SkipGroupsStrategy::m_groups{};

        const std::vector<Group*>& SkipGroupsStrategy::groups() const { return m_groups; }
        void SkipGroupsStrategy::addGroup(Group* /* group */) {}


        const std::vector<Entity*>& CollectEntitiesStrategy::entities() const { return m_entities; }
        void CollectEntitiesStrategy::addEntity(Entity* entity) { m_entities.push_back(entity); }

        const std::vector<Entity*> SkipEntitiesStrategy::m_entities{};

        const std::vector<Entity*>& SkipEntitiesStrategy::entities() const { return m_entities; }
        void SkipEntitiesStrategy::addEntity(Entity* /* entity */) {}


        const std::vector<Brush*>& CollectBrushesStrategy::brushes() const { return m_brushes; }
        void CollectBrushesStrategy::addBrush(Brush* brush) { m_brushes.push_back(brush); }

        const std::vector<Brush*> SkipBrushesStrategy::m_brushes{};

        const std::vector<Brush*>& SkipBrushesStrategy::brushes() const { return m_brushes; }
        void SkipBrushesStrategy::addBrush(Brush* /* brush */) {}
    }
}
