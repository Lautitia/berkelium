<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:variable name="smallcase" select="'abcdefghijklmnopqrstuvwxyz'"/>
<xsl:variable name="uppercase" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'"/>

<!-- ============================================================= -->
<!-- Header: Header                                                -->
<!-- ============================================================= -->
<xsl:template name="comment-header">
	<xsl:text>// Copyright (c) 2012 The Berkelium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

</xsl:text>
</xsl:template>

<!-- ============================================================= -->
<!-- Header: Auto Generated                                        -->
<!-- ============================================================= -->
<xsl:template name="comment-generated">
	<xsl:text>// =========================================
// WARNING:
//   THIS FILE IS AUTOMATICALLY GENERATED!
//   !! ANY CHANGES WILL BE OVERWRITTEN !!
//
// See berkelium/berkelium-api/update.sh
// =========================================

</xsl:text>
</xsl:template>

<!-- ============================================================= -->
<!-- Argument Type                                                 -->
<!-- ============================================================= -->
<xsl:template name="type">
	<xsl:param name="name" select="''"/>
	<xsl:variable name="node" select="/api/mapping[@type=$lang]/type[@name = $name]"/>
	<xsl:variable name="group" select="/api/group[@name = $name]"/>
	<xsl:choose>
		<xsl:when test="$node/@value">
			<xsl:value-of select="$node/@value"/>
		</xsl:when>
		<xsl:when test="$group">
			<xsl:value-of select="/api/mapping[@type=$lang]/@prefix"/>
			<xsl:choose>
				<xsl:when test="$group[@type='class']|$group[@type='interface']">
					<xsl:value-of select="/api/mapping[@type=$lang]/@class-prefix"/>
					<xsl:value-of select="$name"/>
					<xsl:value-of select="/api/mapping[@type=$lang]/@class-postfix"/>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="$name"/>
				</xsl:otherwise>
			</xsl:choose>
			<xsl:value-of select="/api/mapping[@type=$lang]/@postfix"/>
		</xsl:when>
		<xsl:when test="not($name)">
			<xsl:text>void</xsl:text>
		</xsl:when>
		<xsl:otherwise>
			<xsl:text>!!ERROR: Type '</xsl:text>
			<xsl:value-of select="$name"/>
			<xsl:text>' not found!!</xsl:text>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<!-- ============================================================= -->
<!-- Argument List                                                 -->
<!-- ============================================================= -->
<xsl:template name="arguments">
	<xsl:for-each select="arg">
		<xsl:call-template name="type">
			<xsl:with-param name="name" select="@type"/>
		</xsl:call-template>
		<xsl:text> </xsl:text>
		<xsl:value-of select="@name"/>
		<xsl:if test="position() != last()">
			<xsl:text>, </xsl:text>
		</xsl:if>
	</xsl:for-each>
</xsl:template>

<xsl:template name="include-guard-start">
	<!-- TODO: not very important, but some underscores are missing ;-) -->
	<xsl:variable name="guard" select="concat('BERKELIUM_API_', translate($class, $smallcase, $uppercase),'_HPP_')"/>

	<xsl:text>#ifndef </xsl:text>
	<xsl:value-of select="$guard"/>
	<xsl:text>
#define </xsl:text>
	<xsl:value-of select="$guard"/>
	<xsl:text>
#pragma once

</xsl:text>
</xsl:template>

<xsl:template name="include-guard-end">
	<!-- TODO: not very important, but some underscores are missing ;-) -->
	<xsl:variable name="guard" select="concat('BERKELIUM_', translate($class, $smallcase, $uppercase),'_HPP_')"/>

	<xsl:text>#endif // </xsl:text>
	<xsl:value-of select="$guard"/>
	<xsl:text>
</xsl:text>
</xsl:template>

</xsl:stylesheet>
