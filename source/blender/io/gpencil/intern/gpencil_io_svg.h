/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#pragma once

/** \file
 * \ingroup bgpencil
 */
#include "BLI_path_util.h"

#include "DNA_material_types.h"

#include "gpencil_io_base.h"
#include "pugixml.hpp"

struct Main;
struct Material;
struct ARegion;

struct bGPDlayer;
struct bGPDstroke;
struct GpencilExportParams;
struct MaterialGPencilStyle;

namespace blender {
namespace io {
namespace gpencil {

class GpencilExporterSVG : public GpencilExporter {

 public:
  GpencilExporterSVG(const struct GpencilExportParams *params);
  bool write(std::string actual_frame);

 private:
  /* XML doc. */
  pugi::xml_document doc;
  /* Main document node. */
  pugi::xml_node main_node;

  void create_document_header(void);
  void export_layers(void);
  void export_style_list(void);

  void export_point(pugi::xml_node gpl_node,
                    struct bGPDlayer *gpl,
                    struct bGPDstroke *gps,
                    float diff_mat[4][4]);

  void export_stroke_path(pugi::xml_node gpl_node,
                          struct bGPDstroke *gps,
                          float diff_mat[4][4],
                          const bool is_fill);

  void export_stroke_polyline(pugi::xml_node gpl_node,
                              struct bGPDlayer *gpl,
                              struct bGPDstroke *gps,
                              struct MaterialGPencilStyle *gp_style,
                              float diff_mat[4][4],
                              const bool is_fill);
};

}  // namespace gpencil
}  // namespace io
}  // namespace blender
