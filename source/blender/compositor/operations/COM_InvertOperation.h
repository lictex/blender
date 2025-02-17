/* SPDX-FileCopyrightText: 2011 Blender Foundation.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#include "COM_MultiThreadedOperation.h"

namespace blender::compositor {

class InvertOperation : public MultiThreadedOperation {
 private:
  /**
   * Cached reference to the input_program
   */
  SocketReader *input_value_program_;
  SocketReader *input_color_program_;

  bool alpha_;
  bool color_;

 public:
  InvertOperation();

  /**
   * The inner loop of this operation.
   */
  void execute_pixel_sampled(float output[4], float x, float y, PixelSampler sampler) override;

  /**
   * Initialize the execution
   */
  void init_execution() override;

  /**
   * Deinitialize the execution
   */
  void deinit_execution() override;

  void set_color(bool color)
  {
    color_ = color;
  }
  void set_alpha(bool alpha)
  {
    alpha_ = alpha;
  }

  void update_memory_buffer_partial(MemoryBuffer *output,
                                    const rcti &area,
                                    Span<MemoryBuffer *> inputs) override;
};

}  // namespace blender::compositor
