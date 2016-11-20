/*
 * Copyright (C) 2016 Simon Fels <morphis@gravedo.de>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef ANBOX_WM_WINDOW_H_
#define ANBOX_WM_WINDOW_H_

#include "anbox/wm/window_state.h"

#include <vector>
#include <string>

#include <EGL/egl.h>

namespace anbox {
namespace wm {
// FIXME(morphis): move this somewhere else once we have the integration
// with the emugl layer.
class Layer {
public:
    graphics::Rect frame() const { return frame_; }

private:
    graphics::Rect frame_;
};

class Window
{
public:
    typedef std::vector<Window> List;

    Window(const WindowState &state);
    virtual ~Window();

    bool attach();
    void release();

    void update_state(const WindowState &state);

    virtual EGLNativeWindowType native_handle() const;
    WindowState state() const;

private:
    WindowState state_;
};
} // namespace wm
} // namespace anbox

#endif
