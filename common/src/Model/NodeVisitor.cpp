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

#include "NodeVisitor.h"

namespace TrenchBroom {
    namespace Model {
        BaseNodeVisitor::BaseNodeVisitor() :
        m_cancelled(false),
        m_recursionStopped(false) {}

        BaseNodeVisitor::~BaseNodeVisitor() {}

        bool BaseNodeVisitor::cancelled() const {
            return m_cancelled;
        }

        bool BaseNodeVisitor::recursionStopped() {
            const bool result = m_recursionStopped;
            m_recursionStopped = false;
            return result;
        }

        void BaseNodeVisitor::cancel() {
            m_cancelled = true;
        }

        void BaseNodeVisitor::stopRecursion() {
            m_recursionStopped = true;
        }

        NodeVisitor::NodeVisitor() :
        BaseNodeVisitor() {}

        NodeVisitor::~NodeVisitor() {}

        void NodeVisitor::visit(World* world) {
            doVisit(world);
        }

        void NodeVisitor::visit(Layer* layer) {
            doVisit(layer);
        }

        void NodeVisitor::visit(Group* group) {
            doVisit(group);
        }

        void NodeVisitor::visit(Entity* entity) {
            doVisit(entity);
        }

        void NodeVisitor::visit(Brush* brush) {
            doVisit(brush);
        }

        ConstNodeVisitor::ConstNodeVisitor() :
        BaseNodeVisitor() {}

        ConstNodeVisitor::~ConstNodeVisitor() {}

        void ConstNodeVisitor::visit(const World* world) {
            doVisit(world);
        }

        void ConstNodeVisitor::visit(const Layer* layer) {
            doVisit(layer);
        }

        void ConstNodeVisitor::visit(const Group* group) {
            doVisit(group);
        }

        void ConstNodeVisitor::visit(const Entity* entity) {
            doVisit(entity);
        }

        void ConstNodeVisitor::visit(const Brush* brush) {
            doVisit(brush);
        }

        class _NodeVisitorPrototype : public NodeVisitor {
        private:
            void doVisit(World*) override  {}
            void doVisit(Layer*) override  {}
            void doVisit(Group*) override  {}
            void doVisit(Entity*) override {}
            void doVisit(Brush*) override  {}
        };

        class _ConstNodeVisitorPrototype : public ConstNodeVisitor {
        private:
            void doVisit(const World*) override  {}
            void doVisit(const Layer*) override  {}
            void doVisit(const Group*) override  {}
            void doVisit(const Entity*) override {}
            void doVisit(const Brush*) override  {}
        };
    }


    class _NodeVisitorPrototype : public Model::NodeVisitor {
    private:
        void doVisit(Model::World*) override  {}
        void doVisit(Model::Layer*) override  {}
        void doVisit(Model::Group*) override  {}
        void doVisit(Model::Entity*) override {}
        void doVisit(Model::Brush* ) override  {}
    };

    class _ConstNodeVisitorPrototype : public Model::ConstNodeVisitor {
    private:
        void doVisit(const Model::World*) override  {}
        void doVisit(const Model::Layer*) override  {}
        void doVisit(const Model::Group*) override  {}
        void doVisit(const Model::Entity*) override {}
        void doVisit(const Model::Brush*) override  {}
    };
}
