#pragma once

#include "ConsoleGameEngine.h"
#include <iostream>
#include <fstream>
#include <strstream>
#include <algorithm>

#include"ConsoleGameEngine.h"

using namespace std;
enum to_render {Space_Craft, Cube, None};
to_render object = None;

class olcEngine3D : public olcConsoleGameEngine
{
	CHAR_INFO GetColour(float lum){}

public:

	bool OnUserCreate() override{}
	bool OnUserUpdate(float fElapsedTime) override{}
};


struct vec3d { float x, y, z; };
struct mat4x4 { float m[4][4] = { 0 }; };


struct triangle{
	vec3d p[3];

	wchar_t sym; //what's that ?
	short color;
};


struct mesh {
	vector<triangle> tris;
		bool LoadFromObjectFile(string sFilename)
		{
			ifstream f(sFilename);
			if (!f.is_open())
				return false;

			// Local cache of verts
			vector<vec3d> verts;

			while (!f.eof())
			{
				char line[124];
				f.getline(line, 124);

				strstream s;
				s << line;

				char junk;

				if (line[0] == 'v')
				{
					vec3d v;
					s >> junk >> v.x >> v.y >> v.z;
					verts.push_back(v);
				}

				if (line[0] == 'f')
				{
					int f[3];
					s >> junk >> f[0] >> f[1] >> f[2];
					tris.push_back({ verts[f[0] - 1], verts[f[1] - 1], verts[f[2] - 1] });
				}
			}

			return true;
		}
};