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

#include "AnnotationPropertiesFactoryTest.h"

void AnnotationPropertiesFactoryTest::initTestCase()
{
    QSettings::setPath(QSettings::NativeFormat, QSettings::UserScope, QStringLiteral("/tmp"));
}

void AnnotationPropertiesFactoryTest::cleanupTestCase()
{
    QSettings::setPath(QSettings::NativeFormat, QSettings::UserScope, QStringLiteral("$HOME/.config"));
}

void AnnotationPropertiesFactoryTest::TestCreateProperties_Should_SetPropertiesSizeBasedOnConfiguration()
{
    const int size = 13;
    const ToolTypes tool = ToolTypes::Line;
    auto configInstance = Config::instance();
    configInstance->setToolSize(size, tool);
    AnnotationPropertiesFactory propertiesFactory;

    auto properties = propertiesFactory.createProperties(tool);

    QCOMPARE(properties.size(), size);
}

void AnnotationPropertiesFactoryTest::TestCreateProperties_Should_SetPropertiesColorBasedOnConfiguration()
{
    const QColor color(Qt::darkMagenta);
    const ToolTypes tool = ToolTypes::Line;
    auto configInstance = Config::instance();
    configInstance->setToolColor(color, tool);
    AnnotationPropertiesFactory propertiesFactory;

    auto properties = propertiesFactory.createProperties(tool);

    QCOMPARE(properties.color(), color);
}

void AnnotationPropertiesFactoryTest::TestCreateProperties_Should_SetPropertiesForegroundColorBasedOnConfiguration()
{
    const QColor foregroundColor(Qt::darkMagenta);
    const ToolTypes tool = ToolTypes::Number;
    auto configInstance = Config::instance();
    configInstance->setToolForegroundColor(foregroundColor, tool);
    AnnotationPropertiesFactory propertiesFactory;

    auto properties = propertiesFactory.createProperties(tool);

    QCOMPARE(properties.foregroundColor(), foregroundColor);
}

void AnnotationPropertiesFactoryTest::TestCreateProperties_Should_SetPropertiesFillBasedOnConfiguration()
{
    const FillTypes fill = FillTypes::NoFill;
    const ToolTypes tool = ToolTypes::Rect;
    auto configInstance = Config::instance();
    configInstance->setToolFillType(fill, tool);
    AnnotationPropertiesFactory propertiesFactory;

    auto properties = propertiesFactory.createProperties(tool);

    QCOMPARE(properties.fillType(), fill);
}

void AnnotationPropertiesFactoryTest::TestCreateProperties_Should_SetAlwaysFillTypeToFill_When_ItemIsArrow()
{
    const FillTypes fill = FillTypes::NoFill;
    const ToolTypes tool = ToolTypes::Arrow;
    auto configInstance = Config::instance();
    configInstance->setToolFillType(fill, tool);
    AnnotationPropertiesFactory propertiesFactory;

    auto properties = propertiesFactory.createProperties(tool);

    QCOMPARE(properties.fillType(), FillTypes::Fill);
}

void AnnotationPropertiesFactoryTest::TestCreateProperties_Should_SetAlwaysFillTypeToFill_When_ItemIsNumber()
{
    const FillTypes fill = FillTypes::NoFill;
    const ToolTypes tool = ToolTypes::Number;
    auto configInstance = Config::instance();
    configInstance->setToolFillType(fill, tool);
    AnnotationPropertiesFactory propertiesFactory;

    auto properties = propertiesFactory.createProperties(tool);

    QCOMPARE(properties.fillType(), FillTypes::Fill);
}

QTEST_MAIN(AnnotationPropertiesFactoryTest);