{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 5,
			"architecture" : "x86",
			"modernui" : 1
		}
,
		"rect" : [ 178.0, 165.0, 1007.0, 754.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-7",
					"linecount" : 22,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 11.0, 11.0, 595.0, 301.0 ],
					"style" : "",
					"text" : "This file is part of the TaViPaCo (Tangible Virtual Patch Cords)\n\nThe TaViPaCo can be obtained at http://stefanofasciani.com/tavipaco.html\nTaViPaCo Copyright (C) 2018 Stefano Fasciani, University of Wollongong in Dubai\nInquiries: stefanofasciani@stefanofasciani.com\n\nThe TaViPaCo is free software: you can redistribute it and/or modify it under the \nterms of the GNU Lesser General Public License as published by the Free Software \nFoundation, either version 3 of the License, or (at your option) any later version.\n\nThe TaViPaCo is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; \nwithout even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. \nSee the GNU Less General Public License for more details.\n\nYou should have received a copy of the GNU Lesser General Public License along with TaViPaCo. \nIf not, see <http://www.gnu.org/licenses/>.\n\nIf you use the TaViPaCo or any part of it in any system or publication, please acknowledge \nits authors by adding a reference to this pubblication:\n\nS. Fasciani, H. Rahman, 2018, \"Tangible Virtual Patch Cords\" in proceedings of\nInternational Computer Music Conference 2018, Daegu, Korea."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 375.0, 361.666687, 83.0, 22.0 ],
					"style" : "",
					"text" : "gain $1 $2 $3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 375.0, 325.0, 47.0, 22.0 ],
					"style" : "",
					"text" : "0. 1. 1."
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"id" : "obj-4",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 276.909119, 565.0, 317.0, 20.0 ],
					"style" : "",
					"text" : "connect here the signals from the 22 interface inlets"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.784314, 0.145098, 0.023529, 0.0 ],
					"fontface" : 1,
					"id" : "obj-3",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 276.909119, 511.0, 317.0, 20.0 ],
					"style" : "",
					"text" : "connect here the signals to the 22 interface outlets"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 197.0, 591.0, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 23,
					"numoutlets" : 23,
					"outlettype" : [ "", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal" ],
					"patching_rect" : [ 197.0, 537.0, 449.909119, 22.0 ],
					"style" : "",
					"text" : "TaViPaCoMax"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-234",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 545.909119, 412.666687, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-229",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 545.909119, 446.666687, 101.0, 22.0 ],
					"style" : "",
					"text" : "pollinginterval $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-224",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 450.0, 412.666687, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-223",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 450.0, 446.666687, 87.0, 22.0 ],
					"style" : "",
					"text" : "selectserial $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-220",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 343.590942, 446.666687, 96.0, 22.0 ],
					"style" : "",
					"text" : "dumpserialports"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-217",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 223.0, 595.0, 80.0, 20.0 ],
					"style" : "",
					"text" : "Serial RX"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-208",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 470.090912, 325.0, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-207",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 470.090912, 361.666687, 69.0, 22.0 ],
					"style" : "",
					"text" : "ifenable $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-204",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 274.0, 325.0, 54.0, 22.0 ],
					"style" : "",
					"text" : "10 1000"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-203",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 197.0, 325.0, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-202",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 274.0, 361.666687, 90.0, 22.0 ],
					"style" : "",
					"text" : "fadetime $1 $2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-201",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 197.0, 361.666687, 70.0, 22.0 ],
					"style" : "",
					"text" : "verbose $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-200",
					"linecount" : 17,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 673.909119, 325.0, 296.0, 234.0 ],
					"style" : "",
					"text" : "COMMANDS\n\nverbose 1/0\n\nfadetime min max\n\ngain min max exponent\n\nifenable 1/0 (after serial open) enable interface, upon sending 1 a full status update is sent\n\ndumpserialport (shows serial ports)\n\nselectserial (integer starting from 0 identifying one of the port in the dumped list)\n\npollinginterval INT  (0 will stop any int will start)"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"midpoints" : [ 206.5, 483.333344, 206.5, 483.333344 ],
					"source" : [ "obj-201", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"midpoints" : [ 283.5, 405.333344, 206.5, 405.333344 ],
					"source" : [ "obj-202", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-201", 0 ],
					"source" : [ "obj-203", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-202", 0 ],
					"source" : [ "obj-204", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"midpoints" : [ 479.590912, 405.333344, 206.5, 405.333344 ],
					"source" : [ "obj-207", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-207", 0 ],
					"source" : [ "obj-208", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"midpoints" : [ 353.090942, 484.333344, 206.5, 484.333344 ],
					"source" : [ "obj-220", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"midpoints" : [ 459.5, 484.333344, 206.5, 484.333344 ],
					"source" : [ "obj-223", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-223", 0 ],
					"source" : [ "obj-224", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"midpoints" : [ 555.409119, 484.333344, 206.5, 484.333344 ],
					"source" : [ "obj-229", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-229", 0 ],
					"source" : [ "obj-234", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"midpoints" : [ 384.5, 405.833344, 206.5, 405.833344 ],
					"source" : [ "obj-6", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "TaViPaCoMax.maxpat",
				"bootpath" : "/Volumes/SFAXTHD3TB/Research/works/TaViPaCo/github/TaViPaCo/Software/Max",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "TaViPaCoMtO.maxpat",
				"bootpath" : "/Volumes/SFAXTHD3TB/Research/works/TaViPaCo/github/TaViPaCo/Software/Max",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "TaViPaCoFio.maxpat",
				"bootpath" : "/Volumes/SFAXTHD3TB/Research/works/TaViPaCo/github/TaViPaCo/Software/Max",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "TaViPaCoADD.gendsp",
				"bootpath" : "/Volumes/SFAXTHD3TB/Research/works/TaViPaCo/github/TaViPaCo/Software/Max",
				"patcherrelativepath" : ".",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "TaViPaCoMUL.gendsp",
				"bootpath" : "/Volumes/SFAXTHD3TB/Research/works/TaViPaCo/github/TaViPaCo/Software/Max",
				"patcherrelativepath" : ".",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "TaViPaCoParser.js",
				"bootpath" : "/Volumes/SFAXTHD3TB/Research/works/TaViPaCo/github/TaViPaCo/Software/Max",
				"patcherrelativepath" : ".",
				"type" : "TEXT",
				"implicit" : 1
			}
 ],
		"autosave" : 0
	}

}
