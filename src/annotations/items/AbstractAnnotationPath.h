/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef KIMAGEANNOTATOR_ABSTRACTANNOTATIONPATH_H
#define KIMAGEANNOTATOR_ABSTRACTANNOTATIONPATH_H

#include "AbstractAnnotationItem.h"
#include "../../common/helper/ShapeHelper.h"

class AbstractAnnotationPath : public AbstractAnnotationItem
{
public:
    AbstractAnnotationPath(const QPointF &startPosisition, const AnnotationProperties &properties);
    virtual ~AbstractAnnotationPath();
    void addPoint(const QPointF &position, bool modified = false) override;
    void setPosition(const QPointF &newPosition) override;
    void setPointAt(const QPointF &point, int handleIndex) override;
    QPointF pointAt(int index) const override;

protected:
    QPainterPath *mPath;

private:
    void scalePath(const QRectF &rect);
};

#endif //KIMAGEANNOTATOR_ABSTRACTANNOTATIONPATH_H