/*
 * Copyright (c) 2022, Andreas Kling <andreas@ladybird.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/Layout/FrameBox.h>
#include <LibWeb/Painting/PaintableBox.h>

namespace Web::Painting {

class NestedBrowsingContextPaintable final : public PaintableBox {
    GC_CELL(NestedBrowsingContextPaintable, PaintableBox);
    GC_DECLARE_ALLOCATOR(NestedBrowsingContextPaintable);

public:
    static GC::Ref<NestedBrowsingContextPaintable> create(Layout::FrameBox const&);

    virtual void paint(PaintContext&, PaintPhase) const override;

    Layout::FrameBox const& layout_box() const;

private:
    NestedBrowsingContextPaintable(Layout::FrameBox const&);
};

}
