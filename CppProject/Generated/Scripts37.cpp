/*
	NOTE:
	This file was autogenerated by CppGen, changes may be overwritten and forever lost!
	Modify at your own risk!
	
	[ Generated on 2023.06.16 19:54:52 ]
*/

#include "Scripts.hpp"

namespace CppProject
{
	VarType model_shape_generate_plane(ScopeAny self, VecType bend)
	{
		RealType x1, x2, y1, z1, z2, scalef;
		VecType size;
		x1 = sVar(from).Value(X_);
		y1 = sVar(from).Value(Y_);
		z1 = sVar(from).Value(Z_);
		x2 = sVar(to).Value(X_);
		z2 = sVar(to).Value(Z_);
		size = point3D_sub(sVar(to), sVar(from));
		scalef = 0.005;
		BoolType isbent = !vec3_equals(bend, vec3(IntType(0))) && sVar(bend_shape) > 0;
		IntType segaxis = Z_;
		if (isbent)
		{
			if (sInt(bend_part) == e_part_LEFT || sInt(bend_part) == e_part_RIGHT)
				segaxis = X_;
			else
				if (sInt(bend_part) == e_part_BACK || sInt(bend_part) == e_part_FRONT)
					segaxis = Z_;
				else
					if (sInt(bend_part) == e_part_LOWER || sInt(bend_part) == e_part_UPPER)
						segaxis = Z_;
			
			
		}
		VecType texsize, texuv;
		texsize = point3D_sub(sVar(to_noscale), sVar(from_noscale));
		texsize = vec3(texsize.Real(X_) / sVar(texture_size).Value(X_), texsize.Real(Y_) / sVar(texture_size).Value(Y_), texsize.Real(Z_) / sVar(texture_size).Value(Y_));
		texuv = vec2_div(sVar(uv), sVar(texture_size));
		VecType tex1, tex2, tex3, tex4;
		tex1 = point2D_copy(texuv);
		tex2 = point2D_add(tex1, point2D(texsize.Real(X_), IntType(0)));
		tex3 = point2D_add(tex1, point2D(texsize.Real(X_), texsize.Real(Z_)));
		tex4 = point2D_add(tex1, point2D(IntType(0), texsize.Real(Z_)));
		if (sVar(texture_mirror) > 0)
		{
			VecType tmp;
			tmp = tex2;
			tex2 = tex1;
			tex1 = tmp;
			tmp = tex3;
			tex3 = tex4;
			tex4 = tmp;
		}
		RealType detail = IntType(2);
		RealType sharpbend, bendstart, bendend, bendsegsize;
		VarType bendsize;
		BoolType invangle;
		sharpbend = global::_app->project_bend_style == /*"blocky"*/ STR(1878) && sVar(bend_size) == null_ && ((sVec(bend_axis).Real(X_) && !sVec(bend_axis).Real(Y_) && !sVec(bend_axis).Real(Z_)) || (!sVec(bend_axis).Real(X_) && sVec(bend_axis).Real(Y_) && !sVec(bend_axis).Real(Z_)) || (!sVec(bend_axis).Real(X_) && !sVec(bend_axis).Real(Y_) && sVec(bend_axis).Real(Z_)));
		bendsize = (sVar(bend_size) == null_ ? VarType((global::_app->project_bend_style == /*"realistic"*/ STR(1879) ? 4.0 : 1.0)) : sVar(bend_size));
		detail = ((sharpbend > 0) ? IntType(2) : real(max({ bendsize, IntType(2) })));
		if ((sVar(bend_size) != null_ && sVar(bend_size) >= IntType(1)) && sVar(scale).Value(segaxis) > .5)
			detail /= sVar(scale).Value(segaxis);
		bendsegsize = (RealType)bendsize / detail;
		invangle = (sInt(bend_part) == e_part_LOWER || sInt(bend_part) == e_part_BACK || sInt(bend_part) == e_part_LEFT);
		VecType p1, p2;
		VarType n1, n2;
		RealType texp1;
		if (segaxis == X_)
		{
			bendstart = (sVar(bend_offset) - (sVar(position).Value(X_) + x1)) - (RealType)bendsize / 2.0;
			bendend = (sVar(bend_offset) - (sVar(position).Value(X_) + x1)) + (RealType)bendsize / 2.0;
			p1 = point3D(x1, y1, z2);
			p2 = point3D(x1, y1, z1);
			texp1 = tex1.Real(X_);
		}
		else
			if (segaxis == Z_ || segaxis == Y_)
			{
				bendstart = (sVar(bend_offset) - (sVar(position).Value(Z_) + z1)) - (RealType)bendsize / 2.0;
				bendend = (sVar(bend_offset) - (sVar(position).Value(Z_) + z1)) + (RealType)bendsize / 2.0;
				p1 = point3D(x1, y1, z1);
				p2 = point3D(x2, y1, z1);
				texp1 = tex3.Real(Y_);
			}
		
		MatrixType mat;
		if (isbent)
		{
			RealType startp;
			VecType bendvec;
			if (bendstart > IntType(0))
				startp = IntType(0);
			else
				if (bendend < IntType(0))
					startp = IntType(1);
				else
					startp = (IntType(1) - bendend / bendsize);
			
			
			if (invangle)
				startp = IntType(1) - startp;
			bendvec = model_shape_get_bend(bend, startp);
			VecType startscale = vec3(IntType(0));
			if (sharpbend > 0)
				startscale = model_shape_get_bend_scale(self, bendstart, bendend, startp, true, IntType(0), bend);
			mat = model_part_get_bend_matrix(self, { self->id, bendvec, vec3(IntType(0)), vec3_add(startscale, vec3(IntType(1) + (startp * IntType(0)))) });
		}
		else
			mat = matrix_build(0.0, 0.0, 0.0, sVar(rotation).Value(X_), sVar(rotation).Value(Y_), sVar(rotation).Value(Z_), 1.0, 1.0, 1.0);
		
		p1 = point3D_mul_matrix(p1, mat);
		p2 = point3D_mul_matrix(p2, mat);
		n1 = vec3_normalize(vec3_mul_matrix(vec3(IntType(0), IntType(1), IntType(0)), mat));
		n2 = vec3_normalize(vec3_mul_matrix(vec3(IntType(0), -IntType(1), IntType(0)), mat));
		vbuffer_start();
		global::vertex_emissive = sVar(color_emissive);
		global::vertex_wave = sInt(wind_wave);
		global::vertex_wave_zmin = sVar(wind_wave_zmin);
		global::vertex_wave_zmax = sVar(wind_wave_zmax);
		RealType segpos = IntType(0);
		while (segpos < size.Real(segaxis))
		{
			RealType segsize;
			VecType np1, np2;
			VarType nn1, nn2;
			RealType ntexp1;
			if (!isbent || segpos >= bendend)
				segsize = size.Real(segaxis) - segpos;
			else
				if (segpos < bendstart)
					segsize = min({ size.Real(segaxis) - segpos, bendstart });
				else
				{
					segsize = bendsegsize;
					if (segpos == IntType(0))
						segsize -= mod((sVar(from).Value(segaxis) - bendstart), bendsegsize);
					segsize = min({ size.Real(segaxis) - segpos, segsize });
				}
			
			
			segpos += max({ segsize, 0.005 });
			if (segaxis == X_)
			{
				np1 = point3D(x1 + segpos, y1, z2);
				np2 = point3D(x1 + segpos, y1, z1);
				RealType toff = (segpos / size.Real(X_)) * texsize.Real(X_) * negate(sVar(texture_mirror));
				ntexp1 = tex1.Real(X_) + toff;
			}
			else
				if (segaxis == Z_)
				{
					np1 = point3D(x1, y1, z1 + segpos);
					np2 = point3D(x2, y1, z1 + segpos);
					RealType toff = (segpos / size.Real(Z_)) * texsize.Real(Z_);
					ntexp1 = tex3.Real(Y_) - toff;
				}
			
			if (isbent)
			{
				RealType segp;
				VecType bendvec;
				if (segpos < bendstart)
					segp = IntType(0);
				else
					if (segpos >= bendend)
						segp = IntType(1);
					else
						segp = (IntType(1) - (bendend - segpos) / bendsize);
				
				
				if (invangle)
					segp = IntType(1) - segp;
				bendvec = model_shape_get_bend(bend, segp);
				VecType bendscale = vec3(IntType(0));
				if (sharpbend > 0)
					sVec(startscale) = model_shape_get_bend_scale(self, bendstart, bendend, segp, true, segpos, bend);
				mat = model_part_get_bend_matrix(self, { self->id, bendvec, vec3(IntType(0)), vec3_add(bendscale, vec3(IntType(1))) });
			}
			else
				mat = matrix_build(0.0, 0.0, 0.0, sVar(rotation).Value(X_), sVar(rotation).Value(Y_), sVar(rotation).Value(Z_), 1.0, 1.0, 1.0);
			
			np1 = point3D_mul_matrix(np1, mat);
			np2 = point3D_mul_matrix(np2, mat);
			nn1 = vec3_normalize(vec3_mul_matrix(vec3(IntType(0), IntType(1), IntType(0)), mat));
			nn2 = vec3_normalize(vec3_mul_matrix(vec3(IntType(0), -IntType(1), IntType(0)), mat));
			if (sharpbend > 0)
			{
				n1 = null_;
				n2 = null_;
				nn1 = null_;
				nn2 = null_;
			}
			VecType t1, t2, t3, t4;
			if (segaxis == X_)
			{
				t1 = vec2(texp1, tex1.Real(Y_));
				t2 = vec2(ntexp1, tex1.Real(Y_));
				t3 = vec2(ntexp1, tex3.Real(Y_));
				t4 = vec2(texp1, tex3.Real(Y_));
				if (!(sVar(hide_front) > 0))
				{
					vbuffer_add_triangle({ p1, np1, np2, t1, t2, t3, n1, nn1, nn1, sVar(invert) });
					vbuffer_add_triangle({ np2, p2, p1, t3, t4, t1, nn1, n1, n1, sVar(invert) });
				}
				if (!(sVar(hide_back) > 0))
				{
					vbuffer_add_triangle({ np1, p1, np2, t2, t1, t3, nn2, n2, nn2, sVar(invert) });
					vbuffer_add_triangle({ p2, np2, p1, t4, t3, t1, n2, nn2, n2, sVar(invert) });
				}
			}
			else
				if (segaxis == Z_)
				{
					t1 = vec2(tex1.Real(X_), ntexp1);
					t2 = vec2(tex2.Real(X_), ntexp1);
					t3 = vec2(tex2.Real(X_), texp1);
					t4 = vec2(tex1.Real(X_), texp1);
					if (!(sVar(hide_front) > 0))
					{
						vbuffer_add_triangle({ np1, np2, p2, t1, t2, t3, nn1, nn1, n1, sVar(invert) });
						vbuffer_add_triangle({ p2, p1, np1, t3, t4, t1, n1, n1, nn1, sVar(invert) });
					}
					if (!(sVar(hide_back) > 0))
					{
						vbuffer_add_triangle({ np2, np1, p2, t2, t1, t3, nn2, nn2, n2, sVar(invert) });
						vbuffer_add_triangle({ p1, p2, np1, t4, t3, t1, n2, n2, nn2, sVar(invert) });
					}
				}
			
			p1 = np1;
			p2 = np2;
			n1 = nn1;
			n2 = nn2;
			texp1 = ntexp1;
		}
		
		global::vertex_emissive = IntType(0);
		global::vertex_wave = e_vertex_wave_NONE;
		global::vertex_wave_zmin = null_;
		global::vertex_wave_zmax = null_;
		return vbuffer_done();
	}
	
	VarType model_shape_generate_plane_3d(ScopeAny self, VecType bend, VarType alpha)
	{
		if (!is_array(alpha))
			return null_;
		RealType x1, x2, y1, y2, z1, z2, scalef;
		VecType size;
		x1 = sVar(from).Value(X_);
		y1 = sVar(from).Value(Y_);
		z1 = sVar(from).Value(Z_);
		x2 = sVar(to).Value(X_);
		y2 = sVar(to).Value(Y_);
		z2 = sVar(to).Value(Z_);
		size = point3D_sub(sVar(to), sVar(from));
		scalef = 0.005;
		BoolType isbent = !vec3_equals(bend, vec3(IntType(0))) && sVar(bend_shape) > 0;
		IntType segouteraxis, seginneraxis, arrouteraxis, arrinneraxis;
		if (isbent)
		{
			if (sInt(bend_part) == e_part_LEFT || sInt(bend_part) == e_part_RIGHT)
			{
				segouteraxis = Z_;
				seginneraxis = X_;
				arrouteraxis = Y_;
				arrinneraxis = X_;
			}
			else
				if (sInt(bend_part) == e_part_LOWER || sInt(bend_part) == e_part_UPPER)
				{
					segouteraxis = X_;
					seginneraxis = Z_;
					arrouteraxis = X_;
					arrinneraxis = Y_;
				}
				else
				{
					segouteraxis = X_;
					seginneraxis = Z_;
					arrouteraxis = X_;
					arrinneraxis = Y_;
				}
			
			
		}
		else
		{
			segouteraxis = X_;
			seginneraxis = Z_;
			arrouteraxis = X_;
			arrinneraxis = Y_;
		}
		
		VecType texsize, texuv, samplesize, texscale, texsizescale, ptexsize;
		texsize = point3D_sub(sVar(to_noscale), sVar(from_noscale));
		texuv = vec2_div(sVar(uv), sVar(texture_size));
		samplesize = vec2(array_length(VarType::CreateRef(alpha)), array_length(VarType::CreateRef(alpha[IntType(0)])));
		texscale = vec2(ceil(texsize.Real(X_)) / samplesize.Real(X_), ceil(texsize.Real(Z_)) / samplesize.Real(Y_));
		texsizescale = vec2_div(sVar(texture_size), texscale);
		ptexsize = vec2_div(vec2(IntType(1) - 1.0 / 256.0), texsizescale);
		BoolType sharpbend, invangle;
		VarType bendsize;
		RealType bendstart, bendend;
		sharpbend = global::_app->project_bend_style == /*"blocky"*/ STR(1878) && sVar(bend_size) == null_ && ((sVec(bend_axis).Real(X_) && !sVec(bend_axis).Real(Y_) && !sVec(bend_axis).Real(Z_)) || (!sVec(bend_axis).Real(X_) && sVec(bend_axis).Real(Y_) && !sVec(bend_axis).Real(Z_)) || (!sVec(bend_axis).Real(X_) && !sVec(bend_axis).Real(Y_) && sVec(bend_axis).Real(Z_)));
		bendsize = (sVar(bend_size) == null_ ? VarType((global::_app->project_bend_style == /*"realistic"*/ STR(1879) ? 4.0 : 1.0)) : sVar(bend_size));
		invangle = (sInt(bend_part) == e_part_LOWER || sInt(bend_part) == e_part_BACK || sInt(bend_part) == e_part_LEFT);
		if (segouteraxis == X_)
		{
			bendstart = (sVar(bend_offset) - (sVar(position).Value(Z_) + z1)) - (RealType)bendsize / 2.0;
			bendend = (sVar(bend_offset) - (sVar(position).Value(Z_) + z1)) + (RealType)bendsize / 2.0;
		}
		else
			if (segouteraxis == Z_)
			{
				bendstart = (sVar(bend_offset) - (sVar(position).Value(X_) + x1)) - (RealType)bendsize / 2.0;
				bendend = (sVar(bend_offset) - (sVar(position).Value(X_) + x1)) + (RealType)bendsize / 2.0;
			}
		
		ArrType y1p, y2p;
		RealType segouterpos = IntType(0);
		RealType inflateouter = (sVec(inflate).Real(X_) / samplesize.Real(arrouteraxis)) * IntType(2);
		RealType inflateinner = (sVec(inflate).Real(X_) / samplesize.Real(arrinneraxis)) * IntType(2);
		for (IntType outer = IntType(0); outer <= samplesize.Real(arrouteraxis); outer++)
		{
			RealType seginnerpos = IntType(0);
			RealType seginnersize = IntType(1);
			for (IntType inner = IntType(0); inner <= samplesize.Real(arrinneraxis); inner++)
			{
				VecType p1, p2;
				if (seginneraxis == X_)
				{
					p1 = point3D(x1 + seginnerpos, y1, z1 + segouterpos);
					p2 = point3D(x1 + seginnerpos, y2, z1 + segouterpos);
				}
				else
					if (seginneraxis == Z_)
					{
						p1 = point3D(x1 + segouterpos, y1, z1 + seginnerpos);
						p2 = point3D(x1 + segouterpos, y2, z1 + seginnerpos);
					}
				
				MatrixType mat;
				if (isbent)
				{
					RealType segp;
					VecType bendvec;
					if (seginnerpos < bendstart)
						segp = IntType(0);
					else
						if (seginnerpos >= bendend)
							segp = IntType(1);
						else
							segp = (IntType(1) - (bendend - seginnerpos) / bendsize);
					
					
					if (invangle)
						segp = IntType(1) - segp;
					bendvec = model_shape_get_bend(bend, segp);
					VecType bendscale = vec3(IntType(0));
					if (sharpbend)
					{
						if (abs(segp - 0.5) > 0.001)
							segp = round(segp);
						bendscale = model_shape_get_bend_scale(self, bendstart, bendend, segp, false, seginnerpos, bend);
						bendvec = vec3_mul(bend, segp);
					}
					mat = model_part_get_bend_matrix(self, { self->id, bendvec, vec3(IntType(0)), vec3_add(vec3_add(vec3(IntType(1)), bendscale), vec3(segp * scalef)) });
				}
				else
					mat = matrix_build(0.0, 0.0, 0.0, sVar(rotation).Value(X_), sVar(rotation).Value(Y_), sVar(rotation).Value(Z_), 1.0, 1.0, 1.0);
				
				p1 = point3D_mul_matrix(p1, mat);
				p2 = point3D_mul_matrix(p2, mat);
				y1p[outer][inner] = p1;
				y2p[outer][inner] = p2;
				seginnersize = IntType(1);
				if (arrinneraxis == X_)
				{
					if (inner == ((sVar(texture_mirror) > 0) ? 0.0 : samplesize.Real(X_) - IntType(1)) && frac(texsize.Real(X_)) > IntType(0))
						seginnersize = frac(texsize.Real(X_));
				}
				else
					if (arrinneraxis == Y_)
					{
						if (inner == samplesize.Real(Y_) - IntType(1) && frac(texsize.Real(Z_)) > IntType(0))
							seginnersize = frac(texsize.Real(Z_));
					}
				
				seginnerpos += (seginnersize + inflateinner) * sVar(scale).Value(seginneraxis) * texscale.Real(arrinneraxis);
			}
			RealType segoutersize = IntType(1);
			if (arrouteraxis == X_)
			{
				if (outer == ((sVar(texture_mirror) > 0) ? 0.0 : samplesize.Real(X_) - IntType(1)) && frac(texsize.Real(X_)) > IntType(0))
					segoutersize = frac(texsize.Real(X_));
			}
			else
				if (arrouteraxis == Y_)
				{
					if (outer == samplesize.Real(Y_) - IntType(1) && frac(texsize.Real(Z_)) > IntType(0))
						segoutersize = frac(texsize.Real(Z_));
				}
			
			segouterpos += (seginnersize + inflateouter) * sVar(scale).Value(segouteraxis) * texscale.Real(arrouteraxis);
		}
		vbuffer_start();
		global::vertex_emissive = sVar(color_emissive);
		global::vertex_wave = sInt(wind_wave);
		global::vertex_wave_zmin = sVar(wind_wave_zmin);
		global::vertex_wave_zmax = sVar(wind_wave_zmax);
		for (IntType outer = IntType(0); outer < samplesize.Real(arrouteraxis); outer++)
		{
			for (IntType inner = IntType(0); inner < samplesize.Real(arrinneraxis); inner++)
			{
				RealType ax, ay;
				if (seginneraxis == X_)
				{
					ax = inner;
					ay = samplesize.Real(Y_) - IntType(1) - outer;
				}
				else
					if (seginneraxis == Z_)
					{
						ax = outer;
						ay = samplesize.Real(Y_) - IntType(1) - inner;
					}
				
				if (sVar(texture_mirror) > 0)
					ax = samplesize.Real(X_) - IntType(1) - ax;
				if (alpha[ax][ay] < IntType(1))
					continue;
				BoolType wface, eface, aface, bface;
				wface = (ax == IntType(0) || alpha[ax - IntType(1)][ay] < IntType(1));
				eface = (ax == samplesize.Real(X_) - IntType(1) || alpha[ax + IntType(1)][ay] < IntType(1));
				aface = (ay == IntType(0) || alpha[ax][ay - IntType(1)] < IntType(1));
				bface = (ay == samplesize.Real(Y_) - IntType(1) || alpha[ax][ay + IntType(1)] < IntType(1));
				if (sVar(texture_mirror) > 0)
				{
					BoolType tmp = wface;
					wface = eface;
					eface = tmp;
				}
				VecType ptex, t1, t2, t3, t4;
				ptex = point2D(texuv.Real(X_) + ax / texsizescale.Real(X_), texuv.Real(Y_) + ay / texsizescale.Real(Y_));
				t1 = ptex;
				t2 = point2D(ptex.Real(X_) + ptexsize.Real(X_), ptex.Real(Y_));
				t3 = point2D(ptex.Real(X_) + ptexsize.Real(X_), ptex.Real(Y_) + ptexsize.Real(Y_));
				t4 = point2D(ptex.Real(X_), ptex.Real(Y_) + ptexsize.Real(Y_));
				VecType p1, p2, p3, p4, np1, np2, np3, np4;
				if (seginneraxis == X_)
				{
					p1 = y1p[outer + IntType(1)][inner];
					p2 = y2p[outer + IntType(1)][inner];
					p3 = y2p[outer][inner];
					p4 = y1p[outer][inner];
					np1 = y1p[outer + IntType(1)][inner + IntType(1)];
					np2 = y2p[outer + IntType(1)][inner + IntType(1)];
					np3 = y2p[outer][inner + IntType(1)];
					np4 = y1p[outer][inner + IntType(1)];
					if (eface)
					{
						vbuffer_add_triangle({ np2, np1, np4, t1, t2, t3, null_, null_, null_, sVar(invert) });
						vbuffer_add_triangle({ np4, np3, np2, t3, t4, t1, null_, null_, null_, sVar(invert) });
					}
					if (wface)
					{
						vbuffer_add_triangle({ p1, p2, p3, t1, t2, t3, null_, null_, null_, sVar(invert) });
						vbuffer_add_triangle({ p3, p4, p1, t3, t4, t1, null_, null_, null_, sVar(invert) });
					}
					if (!(sVar(hide_front) > 0))
					{
						vbuffer_add_triangle({ p2, np2, np3, t2, t1, t4, null_, null_, null_, sVar(invert) });
						vbuffer_add_triangle({ np3, p3, p2, t4, t3, t2, null_, null_, null_, sVar(invert) });
					}
					if (!(sVar(hide_back) > 0))
					{
						vbuffer_add_triangle({ np1, p1, p4, t2, t1, t4, null_, null_, null_, sVar(invert) });
						vbuffer_add_triangle({ p4, np4, np1, t4, t3, t2, null_, null_, null_, sVar(invert) });
					}
					if (aface)
					{
						vbuffer_add_triangle({ p1, np1, np2, t1, t2, t3, null_, null_, null_, sVar(invert) });
						vbuffer_add_triangle({ np2, p2, p1, t3, t4, t1, null_, null_, null_, sVar(invert) });
					}
					if (bface)
					{
						vbuffer_add_triangle({ p3, np3, np4, t1, t2, t3, null_, null_, null_, sVar(invert) });
						vbuffer_add_triangle({ np4, p4, p3, t3, t4, t1, null_, null_, null_, sVar(invert) });
					}
				}
				else
				{
					p1 = y1p[outer][inner];
					p2 = y1p[outer + IntType(1)][inner];
					p3 = y2p[outer + IntType(1)][inner];
					p4 = y2p[outer][inner];
					np1 = y1p[outer][inner + IntType(1)];
					np2 = y1p[outer + IntType(1)][inner + IntType(1)];
					np3 = y2p[outer + IntType(1)][inner + IntType(1)];
					np4 = y2p[outer][inner + IntType(1)];
					if (eface)
					{
						vbuffer_add_triangle({ np3, np2, p2, t1, t2, t3, null_, null_, null_, sVar(invert) });
						vbuffer_add_triangle({ p2, p3, np3, t3, t4, t1, null_, null_, null_, sVar(invert) });
					}
					if (wface)
					{
						vbuffer_add_triangle({ np1, np4, p4, t1, t2, t3, null_, null_, null_, sVar(invert) });
						vbuffer_add_triangle({ p4, p1, np1, t3, t4, t1, null_, null_, null_, sVar(invert) });
					}
					if (!(sVar(hide_front) > 0))
					{
						vbuffer_add_triangle({ np4, np3, p3, t2, t1, t4, null_, null_, null_, sVar(invert) });
						vbuffer_add_triangle({ p3, p4, np4, t4, t3, t2, null_, null_, null_, sVar(invert) });
					}
					if (!(sVar(hide_back) > 0))
					{
						vbuffer_add_triangle({ np2, np1, p1, t2, t1, t4, null_, null_, null_, sVar(invert) });
						vbuffer_add_triangle({ p1, p2, np2, t4, t3, t2, null_, null_, null_, sVar(invert) });
					}
					if (aface)
					{
						vbuffer_add_triangle({ np1, np2, np3, t1, t2, t3, null_, null_, null_, sVar(invert) });
						vbuffer_add_triangle({ np3, np4, np1, t3, t4, t1, null_, null_, null_, sVar(invert) });
					}
					if (bface)
					{
						vbuffer_add_triangle({ p4, p3, p2, t1, t2, t3, null_, null_, null_, sVar(invert) });
						vbuffer_add_triangle({ p2, p1, p4, t3, t4, t1, null_, null_, null_, sVar(invert) });
					}
				}
				
			}
		}
		global::vertex_emissive = IntType(0);
		global::vertex_wave = e_vertex_wave_NONE;
		global::vertex_wave_zmin = null_;
		global::vertex_wave_zmax = null_;
		return vbuffer_done();
	}
	
	VecType model_shape_get_bend(VecType bend, RealType weight)
	{
		return vec3(bend.Real(X_) * ease(/*"easeinoutquint"*/ STR(556), weight), bend.Real(Y_) * ease(/*"easeinoutquint"*/ STR(556), weight), bend.Real(Z_) * weight);
	}
	
	VecType model_shape_get_bend_scale(ScopeAny self, RealType bendstart, RealType bendend, RealType weight, BoolType start, RealType bendpos, VecType bend)
	{
		if (bendpos > bendstart && bendpos < bendend)
		{
			VecType bendscale;
			if (weight <= 0.5)
				bendscale = vec3(weight * IntType(2));
			else
				bendscale = vec3((IntType(1) - weight) * IntType(2));
			
			IntType bendaxis;
			RealType bendang;
			if (vec3_equals(sVec(bend_axis), vec3(true, false, false)))
				bendaxis = X_;
			else
				if (vec3_equals(sVec(bend_axis), vec3(false, true, false)))
					bendaxis = Y_;
				else
					if (vec3_equals(sVec(bend_axis), vec3(false, false, true)))
						bendaxis = Z_;
			
			
			bendang = abs(bend.Real(bendaxis));
			if (bendang > IntType(90))
				bendang -= (bendang - IntType(90)) * IntType(2);
			RealType bendperc = percent(bendang, IntType(0), IntType(90));
			bendperc = clamp(bendperc, IntType(0), IntType(1));
			bendscale = vec3_mul(bendscale, bendperc);
			for (IntType i = X_; i <= Z_; i++)
				bendscale.Real(i) = ease(/*"easeincubic"*/ STR(548), bendscale.Real(i));
			bendscale = vec3_div(bendscale, 2.5);
			bendscale.Real(bendaxis) = IntType(0);
			return bendscale;
		}
		else
			return vec3(IntType(0));
		
		return VecType();
	}
	
	RealType model_shape_update_color(ScopeAny self)
	{
		if (sVar(model_file) == null_)
			return IntType(0);
		if (sInt(model_color_name_map) == null_)
			return IntType(0);
		if (sInt(model_color_map) == null_)
			sInt(model_color_map) = ds_map_create();
		else
			ds_map_clear(sInt(model_color_map));
		
		VarType key = ds_map_find_first(sInt(model_color_name_map));
		while (!is_undefined(key))
		{
			IntType color;
			switch (StringType(ds_map_find_value(sInt(model_color_name_map), key)).id)
			{
				case 592: // white
				{
					color = c_minecraft_white;
					break;
				}
				case 593: // orange
				{
					color = c_minecraft_orange;
					break;
				}
				case 594: // magenta
				{
					color = c_minecraft_magenta;
					break;
				}
				case 595: // light_blue
				{
					color = c_minecraft_light_blue;
					break;
				}
				case 596: // yellow
				{
					color = c_minecraft_yellow;
					break;
				}
				case 597: // lime
				{
					color = c_minecraft_lime;
					break;
				}
				case 598: // pink
				{
					color = c_minecraft_pink;
					break;
				}
				case 599: // gray
				{
					color = c_minecraft_gray;
					break;
				}
				case 600: // light_gray
				{
					color = c_minecraft_light_gray;
					break;
				}
				case 601: // cyan
				{
					color = c_minecraft_cyan;
					break;
				}
				case 602: // purple
				{
					color = c_minecraft_purple;
					break;
				}
				case 603: // blue
				{
					color = c_minecraft_blue;
					break;
				}
				case 604: // brown
				{
					color = c_minecraft_brown;
					break;
				}
				case 605: // green
				{
					color = c_minecraft_green;
					break;
				}
				case 606: // red
				{
					color = c_minecraft_red;
					break;
				}
				case 607: // black
				{
					color = c_minecraft_black;
					break;
				}
				default:
					color = c_white;
			}
			
			ds_map_add(sInt(model_color_map), key, color);
			key = ds_map_find_next(sInt(model_color_name_map), key);
		}
		
		return 0.0;
	}
	
	RealType mod_fix(VarType xx, VarType yy)
	{
		while (xx < IntType(0))
			xx += yy;
		
		return (mod(xx, yy));
	}
	
	VarType movie_audio_file_add(StringType fn)
	{
		return lib_movie_audio_file_add(fn);
	}
	
	VarType movie_audio_file_decode(StringType src, StringType dest)
	{
		return lib_movie_audio_file_decode(src, dest);
	}
	
	VarType movie_audio_sound_add(VarType file, RealType play, VarType volume, VarType pitch, VarType start, VarType ed)
	{
		return lib_movie_audio_sound_add(file, play, volume, pitch, start, ed);
	}
	
	VarType movie_done()
	{
		return lib_movie_done();
	}
	
	VarType movie_frame(StringType fn)
	{
		return lib_movie_frame(fn);
	}
	
	VarType movie_set(VarType width, VarType height, RealType bitrate, RealType framerate, BoolType audio)
	{
		return lib_movie_set(width, height, bitrate, framerate, audio);
	}
	
	VarType movie_start(StringType fn, StringType format)
	{
		return lib_movie_start(fn, format);
	}
	
	void nbt_debug_tag_compound(VarType name, VarType map)
	{
		VarType key = ds_map_find_first((IntType)(map));
		debug({ /*"[TAG_Compound] "*/ STR(1880) + name });
		debug({ /*"{"*/ STR(1245) });
		global::debug_indent++;
		while (!is_undefined(key))
		{
			if (!string_contains(key, /*"_NBT_"*/ STR(1006)))
			{
				switch ((IntType)DsMap(map).Value(key + /*"_NBT_type"*/ STR(1881)))
				{
					case e_nbt_TAG_BYTE:
					{
						debug({ /*"[TAG_Byte] "*/ STR(1882) + key, DsMap(map).Value(key) });
						break;
					}
					case e_nbt_TAG_SHORT:
					{
						debug({ /*"[TAG_Short] "*/ STR(1883) + key, DsMap(map).Value(key) });
						break;
					}
					case e_nbt_TAG_INT:
					{
						debug({ /*"[TAG_Int] "*/ STR(1884) + key, DsMap(map).Value(key) });
						break;
					}
					case e_nbt_TAG_LONG:
					{
						debug({ /*"[TAG_Long] "*/ STR(1885) + key, DsMap(map).Value(key) });
						break;
					}
					case e_nbt_TAG_FLOAT:
					{
						debug({ /*"[TAG_Float] "*/ STR(1886) + key, DsMap(map).Value(key) });
						break;
					}
					case e_nbt_TAG_DOUBLE:
					{
						debug({ /*"[TAG_Double] "*/ STR(1887) + key, DsMap(map).Value(key) });
						break;
					}
					case e_nbt_TAG_BYTE_ARRAY:
					{
						debug({ /*"[TAG_Byte_Array] "*/ STR(1888) + key });
						global::debug_indent++;
						debug({ /*"Length"*/ STR(997), DsMap(map).Value(key + /*"_NBT_length"*/ STR(1889)) });
						global::debug_indent--;
						break;
					}
					case e_nbt_TAG_STRING:
					{
						debug({ /*"[TAG_String] "*/ STR(1890) + key, DsMap(map).Value(key) });
						break;
					}
					case e_nbt_TAG_LIST:
					{
						nbt_debug_tag_list(key, DsMap(map).Value(key), DsMap(map).Value(key + /*"_NBT_listtype"*/ STR(1891)));
						break;
					}
					case e_nbt_TAG_COMPOUND:
					{
						nbt_debug_tag_compound(key, DsMap(map).Value(key));
						break;
					}
					case e_nbt_TAG_INT_ARRAY:
					{
						debug({ /*"[TAG_Int_Array] "*/ STR(1892) + key });
						global::debug_indent++;
						debug({ /*"Length"*/ STR(997), DsMap(map).Value(key + /*"_NBT_length"*/ STR(1889)) });
						global::debug_indent--;
						break;
					}
					case e_nbt_TAG_LONG_ARRAY:
					{
						debug({ /*"[TAG_Long_Array] "*/ STR(1893) + key });
						global::debug_indent++;
						debug({ /*"Length"*/ STR(997), DsMap(map).Value(key + /*"_NBT_length"*/ STR(1889)) });
						global::debug_indent--;
						break;
					}
					default:
						debug({ /*"[TAG_Empty] "*/ STR(1894) + key, DsMap(map).Value(key) });
						break;
				}
				
			}
			key = ds_map_find_next((IntType)(map), key);
		}
		
		global::debug_indent--;
		debug({ /*"}"*/ STR(1246) });
	}
	
	void nbt_debug_tag_list(VarType name, VarType list, VarType listtype)
	{
		StringType listtypestr;
		switch ((IntType)listtype)
		{
			case e_nbt_TAG_BYTE:
			{
				listtypestr = /*"TAG_Byte"*/ STR(1895);
				break;
			}
			case e_nbt_TAG_SHORT:
			{
				listtypestr = /*"TAG_Short"*/ STR(1896);
				break;
			}
			case e_nbt_TAG_INT:
			{
				listtypestr = /*"TAG_Int"*/ STR(1897);
				break;
			}
			case e_nbt_TAG_LONG:
			{
				listtypestr = /*"TAG_Long"*/ STR(1898);
				break;
			}
			case e_nbt_TAG_FLOAT:
			{
				listtypestr = /*"TAG_Float"*/ STR(1899);
				break;
			}
			case e_nbt_TAG_DOUBLE:
			{
				listtypestr = /*"TAG_Double"*/ STR(1900);
				break;
			}
			case e_nbt_TAG_BYTE_ARRAY:
			{
				listtypestr = /*"TAG_Byte_Array"*/ STR(1901);
				break;
			}
			case e_nbt_TAG_STRING:
			{
				listtypestr = /*"TAG_String"*/ STR(1902);
				break;
			}
			case e_nbt_TAG_LIST:
			{
				listtypestr = /*"TAG_List"*/ STR(1903);
				break;
			}
			case e_nbt_TAG_COMPOUND:
			{
				listtypestr = /*"TAG_Compound"*/ STR(1904);
				break;
			}
			case e_nbt_TAG_INT_ARRAY:
			{
				listtypestr = /*"TAG_Int_Array"*/ STR(1905);
				break;
			}
			case e_nbt_TAG_LONG_ARRAY:
			{
				listtypestr = /*"TAG_Long_Array"*/ STR(1906);
				break;
			}
			default:
				listtypestr = /*"TAG_Empty"*/ STR(1907);
				break;
		}
		
		debug({ /*"[TAG_List of "*/ STR(1908) + listtypestr + /*"] "*/ STR(1909) + name });
		debug({ /*"{"*/ STR(1245) });
		global::debug_indent++;
		for (IntType i = IntType(0); i < ds_list_size((IntType)(list)); i++)
		{
			switch ((IntType)listtype)
			{
				case e_nbt_TAG_BYTE:
				case e_nbt_TAG_SHORT:
				case e_nbt_TAG_INT:
				case e_nbt_TAG_LONG:
				case e_nbt_TAG_FLOAT:
				case e_nbt_TAG_DOUBLE:
				case e_nbt_TAG_STRING:
				{
					debug({ string(DsList(list).Value(i)) + /*","*/ STR(1070) });
					break;
				}
				case e_nbt_TAG_BYTE_ARRAY:
				{
					break;
				}
				case e_nbt_TAG_LIST:
				{
					break;
				}
				case e_nbt_TAG_COMPOUND:
				{
					nbt_debug_tag_compound(/*""*/ STR(0), DsList(list).Value(i));
					break;
				}
				case e_nbt_TAG_INT_ARRAY:
				{
					break;
				}
				case e_nbt_TAG_LONG_ARRAY:
				{
					break;
				}
			}
			
		}
		global::debug_indent--;
		debug({ /*"}"*/ STR(1246) });
	}
	
	IntType nbt_read_tag_compound()
	{
		IntType map = ds_string_map_create();
		while (!buffer_is_eof())
		{
			IntType type = buffer_read_byte();
			if (type == e_nbt_TAG_END)
				break;
			if (type >= e_nbt_amount)
			{
				log({ /*"TAG_Compound error"*/ STR(1910), /*"Invalid tag"*/ STR(1911) });
				ds_map_destroy(map);
				return null_;
			}
			StringType name = buffer_read_string_short_be();
			DsMap(map)[name + /*"_NBT_type"*/ STR(1881)] = type;
			switch ((IntType)type)
			{
				case e_nbt_TAG_BYTE:
				{
					DsMap(map)[name] = buffer_read_byte();
					break;
				}
				case e_nbt_TAG_SHORT:
				{
					DsMap(map)[name] = buffer_read_short_be();
					break;
				}
				case e_nbt_TAG_INT:
				{
					DsMap(map)[name] = buffer_read_int_be();
					break;
				}
				case e_nbt_TAG_LONG:
				{
					DsMap(map)[name] = buffer_read_long_be();
					break;
				}
				case e_nbt_TAG_FLOAT:
				{
					DsMap(map)[name] = buffer_read_float_be();
					break;
				}
				case e_nbt_TAG_DOUBLE:
				{
					DsMap(map)[name] = buffer_read_double_be();
					break;
				}
				case e_nbt_TAG_BYTE_ARRAY:
				{
					RealType len = buffer_read_int_be();
					DsMap(map)[name] = buffer_tell(global::buffer_current);
					DsMap(map)[name + /*"_NBT_length"*/ STR(1889)] = len;
					buffer_skip(len);
					break;
				}
				case e_nbt_TAG_STRING:
				{
					DsMap(map)[name] = buffer_read_string_short_be();
					break;
				}
				case e_nbt_TAG_LIST:
				{
					IntType listtype, list;
					RealType listlen;
					listtype = buffer_read_byte();
					listlen = buffer_read_int_be();
					list = nbt_read_tag_list(listtype, listlen);
					if (list == null_)
					{
						ds_map_destroy(map);
						return null_;
					}
					ds_map_add_list(map, name, list);
					DsMap(map)[name + /*"_NBT_listtype"*/ STR(1891)] = listtype;
					break;
				}
				
				case e_nbt_TAG_COMPOUND:
				{
					IntType nmap = nbt_read_tag_compound();
					if (nmap == null_)
					{
						ds_map_destroy(map);
						return null_;
					}
					ds_map_add_map(map, name, nmap);
					break;
				}
				
				case e_nbt_TAG_INT_ARRAY:
				{
					RealType len = buffer_read_int_be();
					DsMap(map)[name] = buffer_tell(global::buffer_current);
					DsMap(map)[name + /*"_NBT_length"*/ STR(1889)] = len;
					buffer_skip(len * IntType(4));
					break;
				}
				
				case e_nbt_TAG_LONG_ARRAY:
				{
					RealType len = buffer_read_int_be();
					DsMap(map)[name] = buffer_tell(global::buffer_current);
					DsMap(map)[name + /*"_NBT_length"*/ STR(1889)] = len;
					buffer_skip(len * IntType(8));
					break;
				}
				
			}
			
		}
		
		return map;
	}
	
}
