/* SPDX-FileCopyrightText: 2011 Blender Foundation.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#include "COM_Node.h"

namespace blender::compositor {

/**
 * \brief GlareNode
 * \ingroup Node
 */
class GlareNode : public Node {
 public:
  GlareNode(bNode *editor_node);
  void convert_to_operations(NodeConverter &converter,
                             const CompositorContext &context) const override;
};

}  // namespace blender::compositor
