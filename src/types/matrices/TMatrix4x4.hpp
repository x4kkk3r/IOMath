#ifndef _IO_MATH_TMATRIX_4X4_HPP
#define _IO_MATH_TMATRIX_4X4_HPP

#include "../vectors/TVector4.hpp"
#include "../../detail/ComputeBasicMatrixFunctions.hpp"

#include <cassert>

namespace IOMath
{
	namespace Types
	{
		template <typename T>
		struct TMatrix<4, 4, T>
		{
			using row_t = TVector<4, T>;
			using column_t = TVector<4, T>;
			using data_t = TVector<4, T>;
		private:
			data_t data[data_t::Size()];
		public:
			constexpr TMatrix() noexcept = default;
			constexpr TMatrix(TMatrix const &other) noexcept = default;
			constexpr explicit TMatrix(T scalar) noexcept :
				data
				{
					data_t(scalar, 0, 0, 0),
					data_t(0, scalar, 0, 0),
					data_t(0, 0, scalar, 0),
					data_t(0, 0, 0, scalar)
				} {}

			constexpr TMatrix(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o, T p) noexcept :
			data
			{
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					data_t(a, e, i, m),
					data_t(b, f, j, n),
					data_t(c, g, k, o),
					data_t(d, h, l, p)
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					data_t(a, b, c, d),
					data_t(e, f, g, h),
					data_t(i, j, k, l),
					data_t(m, n, o, p)
				#endif
			} {}	
				
			constexpr TMatrix(data_t const &first, data_t const &second, data_t const& third, data_t const &fourth) noexcept :
				data
				{
					data_t(first),
					data_t(second),
					data_t(third),
					data_t(fourth)
				} {}
			
			template <typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J, typename K, typename L, typename M, typename N, typename O, typename P>
			constexpr TMatrix(A a, B b, C c, D d, E e, F f, G g, H h, I i, J j, K k, L l, M m, N n, O o, P p) noexcept : 
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(a, e, i, m),
						data_t(b, f, j, n),
						data_t(c, g, k, o),
						data_t(d, h, l, p)
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(a, b, c, d),
						data_t(e, f, g, h),
						data_t(i, j, k, l),
						data_t(m, n, o, p)
					#endif
				} {}

			template <typename A, typename B, typename C, typename D>
			constexpr TMatrix(TVector<4, A> const &first, TVector<4, B> const &second, TVector<4, C> const &third, TVector<4, D> const &fourth) noexcept :
				data
				{
					data_t(first),
					data_t(second),
					data_t(third),
					data_t(fourth)
				} {}

			template <typename U>
			constexpr TMatrix(TMatrix<2, 2, U> const &other) noexcept :
				data
				{
					data_t(other[0], 0, 0),
					data_t(other[1], 0, 0),
					data_t(),
					data_t()
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<2, 3, U> const &other) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(other[0], 0, 0),
						data_t(other[1], 0, 0),
						data_t(other[2], 0, 0),
						data_t()
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(other[0], 0),
						data_t(other[1], 0),
						data_t(),
						data_t()
					#endif
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<2, 4, U> const &other) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(other[0], 0, 0),
						data_t(other[1], 0, 0),
						data_t(other[2], 0, 0),
						data_t(other[3], 0, 0)
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(other[0]),
						data_t(other[1]),
						data_t(),
						data_t()
					#endif
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<3, 2, U> const &other) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(other[0], 0),
						data_t(other[1], 0),
						data_t(),
						data_t()
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(other[0], 0, 0),
						data_t(other[1], 0, 0),
						data_t(other[2], 0, 0),
						data_t()
					#endif
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<3, 3, U> const &other) noexcept :
				data
				{
					data_t(other[0], 0),
					data_t(other[1], 0),
					data_t(other[2], 0),
					data_t()
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<3, 4, U> const &other) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(other[0], 0),
						data_t(other[1], 0),
						data_t(other[2], 0),
						data_t(other[3], 0)
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(other[0]),
						data_t(other[1]),
						data_t(other[2]),
						data_t()
					#endif
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<4, 2, U> const &other) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(other[0]),
						data_t(other[1]),
						data_t(),
						data_t()
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(other[0], 0, 0),
						data_t(other[1], 0, 0),
						data_t(other[2], 0, 0),
						data_t(other[3], 0, 0)
					#endif
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<4, 3, U> const &other) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(other[0]),
						data_t(other[1]),
						data_t(other[2]),
						data_t()
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(other[0], 0),
						data_t(other[1], 0),
						data_t(other[2], 0),
						data_t(other[3], 0)
					#endif
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<4, 4, U> const &other) noexcept :
				data
				{
					data_t(other[0]),
					data_t(other[1]),
					data_t(other[2]),
					data_t(other[3])
				} {}
			
			template <typename U>
			constexpr TMatrix(TMatrix<2, 4, T> const &otherA, TMatrix<2, 4, T> const &otherB) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(otherA[0], otherB[0]),
						data_t(otherA[1], otherB[1]),
						data_t(otherA[2], otherB[2]),
						data_t(otherA[3], otherB[3])
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(otherA[0]),
						data_t(otherA[1]),
						data_t(otherB[0]),
						data_t(otherB[1])
					#endif
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<4, 2, T> const &otherA, TMatrix<4, 2, T> const &otherB) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(otherA[0]),
						data_t(otherA[1]),
						data_t(otherB[0]),
						data_t(otherB[1])
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(otherA[0], otherB[0]),
						data_t(otherA[1], otherB[1]),
						data_t(otherA[2], otherB[2]),
						data_t(otherA[3], otherB[3])
					#endif
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<2, 2, U> const &otherA, TMatrix<2, 2, U> const &otherB, TMatrix<2, 2, U> const &otherC, TMatrix<2, 2, U> const &otherD) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(otherA[0], otherC[0]),
						data_t(otherA[1], otherC[1]),
						data_t(otherB[0], otherD[0]),
						data_t(otherB[1], otherD[1])
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(otherA[0], otherB[0]),
						data_t(otherA[1], otherB[1]),
						data_t(otherC[0], otherD[0]),
						data_t(otherC[1], otherD[1])
					#endif
				} {}

			template <typename U>
			static constexpr TMatrix<4, 4, T> FromQuaternion(TQuaternion<U> const &quaternion) noexcept
			{
				T const quatW = quaternion.w;
				T const quatX = quaternion.x;
				T const quatY = quaternion.y;
				T const quatZ = quaternion.z;

				T const qxx = quatX * quatX;
				T const qyy = quatY * quatY;
				T const qzz = quatZ * quatZ;
				T const qxz = quatX * quatZ;
				T const qxy = quatX * quatY;
				T const qyz = quatY * quatZ;
				T const qwx = quatW * quatX;
				T const qwy = quatW * quatY;
				T const qwz = quatW * quatZ;

				T const zero = static_cast<T>(0);
				T const one = static_cast<T>(1);
				T const two = static_cast<T>(2);

				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					return TMatrix<4, 4, T>
					(
						one - two * (qyy +  qzz), two * (qxy + qwz), two * (qxz - qwy), zero,
						two * (qxy - qwz), one - two * (qxx +  qzz), two * (qyz + qwx), zero,
						two * (qxz + qwy), two * (qyz - qwx), one - two * (qxx +  qyy), zero,
						zero, zero, zero, one
					);
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					return TMatrix<4, 4, T>
					(
						one - two * (qyy +  qzz), two * (qxy - qwz), two * (qxz + qwy), zero,
						two * (qxy + qwz), one - two * (qxx +  qzz), two * (qyz - qwx), zero,
						two * (qxz - qwy), two * (qyz + qwx), one - two * (qxx +  qyy), zero,
						zero, zero, zero, one
					);
				#endif
			}

			static constexpr TMatrix<4, 4, T> Identity() noexcept
			{
				T const zero = static_cast<T>(0);
				T const one = static_cast<T>(1);

				return TMatrix<4, 4, T>
				(
					one, zero, zero, zero,
					zero, one, zero, zero,
					zero, zero, one, zero,
					zero, zero, zero, one
				);
			}

			static constexpr size_t Rows() noexcept
			{
				return column_t::Size();
			}
			static constexpr size_t Columns() noexcept
			{
				return row_t::Size();
			}

			constexpr data_t & operator[](size_t index) noexcept
			{
				#ifdef IO_MATH_SAFE_BRACKETS_OPERATOR
					assert(index >= 0 && index < TMatrix::Rows());
				#endif

				return data[index];
			}
			constexpr data_t const & operator[](size_t index) const noexcept
			{
				#ifdef IO_MATH_SAFE_BRACKETS_OPERATOR
					assert(index >= 0 && index < TMatrix::Rows());
				#endif

				return data[index];
			}
		
			constexpr TMatrix<4, 4, T>& operator=(TMatrix<4, 4, T> const &other) noexcept
			{
				memcpy(this->data, other.data, sizeof(T) * 16);

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 4, T> & operator=(TMatrix<4, 4, U> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
				this->data[2] = other[2];
				this->data[3] = other[3];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 4, T> & operator+=(U scalar) noexcept
			{
				this->data[0] += scalar;
				this->data[1] += scalar;
				this->data[2] += scalar;
				this->data[3] += scalar;
				
				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 4, T> & operator+=(TMatrix<4, 4, U> const &other) noexcept
			{
				this->data[0] += other[0];
				this->data[1] += other[1];
				this->data[2] += other[2];
				this->data[3] += other[3];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 4, T> & operator-=(U scalar) noexcept
			{
				this->data[0] -= scalar;
				this->data[1] -= scalar;
				this->data[2] -= scalar;
				this->data[3] -= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 4, T> & operator-=(TMatrix<4, 4, U> const &other) noexcept
			{
				this->data[0] -= other[0];
				this->data[1] -= other[1];
				this->data[2] -= other[2];
				this->data[3] -= other[3];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 4, T> & operator*=(U scalar) noexcept
			{
				this->data[0] *= scalar;
				this->data[1] *= scalar;
				this->data[2] *= scalar;
				this->data[3] *= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 4, T> & operator*=(TMatrix<4, 4, U> const &other) noexcept
			{
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					T const lObjectA = this->data[0][0];
					T const lObjectB = this->data[1][0];
					T const lObjectC = this->data[2][0];
					T const lObjectD = this->data[3][0];
					T const lObjectE = this->data[0][1];
					T const lObjectF = this->data[1][1];
					T const lObjectG = this->data[2][1];
					T const lObjectH = this->data[3][1];
					T const lObjectI = this->data[0][2];
					T const lObjectJ = this->data[1][2];
					T const lObjectK = this->data[2][2];
					T const lObjectL = this->data[3][2];
					T const lObjectM = this->data[0][3];
					T const lObjectN = this->data[1][3];
					T const lObjectO = this->data[2][3];
					T const lObjectP = this->data[3][3];

					T const rObjectA = other[0][0];
					T const rObjectB = other[1][0];
					T const rObjectC = other[2][0];
					T const rObjectD = other[3][0];
					T const rObjectE = other[0][1];
					T const rObjectF = other[1][1];
					T const rObjectG = other[2][1];
					T const rObjectH = other[3][1];
					T const rObjectI = other[0][2];
					T const rObjectJ = other[1][2];
					T const rObjectK = other[2][2];
					T const rObjectL = other[3][2];
					T const rObjectM = other[0][3];
					T const rObjectN = other[1][3];
					T const rObjectO = other[2][3];
					T const rObjectP = other[3][3];
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					T const lObjectA = this->data[0][0];
					T const lObjectB = this->data[0][1];
					T const lObjectC = this->data[0][2];
					T const lObjectD = this->data[0][3];
					T const lObjectE = this->data[1][0];
					T const lObjectF = this->data[1][1];
					T const lObjectG = this->data[1][2];
					T const lObjectH = this->data[1][3];
					T const lObjectI = this->data[2][0];
					T const lObjectJ = this->data[2][1];
					T const lObjectK = this->data[2][2];
					T const lObjectL = this->data[2][3];
					T const lObjectM = this->data[3][0];
					T const lObjectN = this->data[3][1];
					T const lObjectO = this->data[3][2];
					T const lObjectP = this->data[3][3];

					T const rObjectA = other[0][0];
					T const rObjectB = other[0][1];
					T const rObjectC = other[0][2];
					T const rObjectD = other[0][3];
					T const rObjectE = other[1][0];
					T const rObjectF = other[1][1];
					T const rObjectG = other[1][2];
					T const rObjectH = other[1][3];
					T const rObjectI = other[2][0];
					T const rObjectJ = other[2][1];
					T const rObjectK = other[2][2];
					T const rObjectL = other[2][3];
					T const rObjectM = other[3][0];
					T const rObjectN = other[3][1];
					T const rObjectO = other[3][2];
					T const rObjectP = other[3][3];
				#endif

				return (*this = TMatrix<4, 4, T>
				(
					lObjectA * rObjectA + lObjectB * rObjectE + lObjectC * rObjectI + lObjectD * rObjectM,
					lObjectA * rObjectB + lObjectB * rObjectF + lObjectC * rObjectJ + lObjectD * rObjectN,
					lObjectA * rObjectC + lObjectB * rObjectG + lObjectC * rObjectK + lObjectD * rObjectO,
					lObjectA * rObjectD + lObjectB * rObjectH + lObjectC * rObjectL + lObjectD * rObjectP,
					lObjectE * rObjectA + lObjectF * rObjectE + lObjectG * rObjectI + lObjectH * rObjectM,
					lObjectE * rObjectB + lObjectF * rObjectF + lObjectG * rObjectJ + lObjectH * rObjectN,
					lObjectE * rObjectC + lObjectF * rObjectG + lObjectG * rObjectK + lObjectH * rObjectO,
					lObjectE * rObjectD + lObjectF * rObjectH + lObjectG * rObjectL + lObjectH * rObjectP,
					lObjectI * rObjectA + lObjectJ * rObjectE + lObjectK * rObjectI + lObjectL * rObjectM,
					lObjectI * rObjectB + lObjectJ * rObjectF + lObjectK * rObjectJ + lObjectL * rObjectN,
					lObjectI * rObjectC + lObjectJ * rObjectG + lObjectK * rObjectK + lObjectL * rObjectO,
					lObjectI * rObjectD + lObjectJ * rObjectH + lObjectK * rObjectL + lObjectL * rObjectP,
					lObjectM * rObjectA + lObjectN * rObjectE + lObjectO * rObjectI + lObjectP * rObjectM,
					lObjectM * rObjectB + lObjectN * rObjectF + lObjectO * rObjectJ + lObjectP * rObjectN,
					lObjectM * rObjectC + lObjectN * rObjectG + lObjectO * rObjectK + lObjectP * rObjectO,
					lObjectM * rObjectD + lObjectN * rObjectH + lObjectO * rObjectL + lObjectP * rObjectP
				));
			}
			template <typename U>
			constexpr TMatrix<4, 4, T> & operator/=(U scalar) noexcept
			{
				this->data[0] /= scalar;
				this->data[1] /= scalar;
				this->data[2] /= scalar;
				this->data[3] /= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 4, T> & operator/=(TMatrix<4, 4, U> const &other) noexcept
			{
				return *this *= detail::ComputeInverse(other);
			}

			constexpr TMatrix<4, 4, T> & operator++() noexcept
			{
				++this->data[0];
				++this->data[1];
				++this->data[2];
				++this->data[3];

				return *this;
			}
			constexpr TMatrix<4, 4, T> & operator--() noexcept
			{
				--this->data[0];
				--this->data[1];
				--this->data[2];
				--this->data[3];

				return *this;
			}
			constexpr TMatrix<4, 4, T> & operator++(int) noexcept
			{
				TMatrix<4, 4, T> result = TMatrix<4, 4, T>(*this);

				++(*this);

				return result;
			}
			constexpr TMatrix<4, 4, T> & operator--(int) noexcept
			{
				TMatrix<4, 4, T> result = TMatrix<4, 4, T>(*this);

				--(*this);

				return result;
			}
		};

		template <typename T>
		constexpr TMatrix<4, 4, T> operator+(TMatrix<4, 4, T> const &object) noexcept
		{
			return object;
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator-(TMatrix<4, 4, T> const &object) noexcept
		{
			return TMatrix<4, 4, T>
			(
				-object[0],
				-object[1],
				-object[2],
				-object[3]
			);
		}
	
		template <typename T>
		constexpr TMatrix<4, 4, T> operator+(T scalar, TMatrix<4, 4, T> const &object) noexcept
		{
			return TMatrix<4, 4, T>
			(
				scalar + object[0],
				scalar + object[1],
				scalar + object[2],
				scalar + object[3]
			);
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator+(TMatrix<4, 4, T> const &object, T scalar) noexcept
		{
			return TMatrix<4, 4, T>
			(
				object[0] + scalar,
				object[1] + scalar,
				object[2] + scalar,
				object[3] + scalar
			);
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator+(TMatrix<4, 4, T> const &lObject, TMatrix<4, 4, T> const &rObject) noexcept
		{
			return TMatrix<4, 4, T>
			(
				lObject[0] + rObject[0],
				lObject[1] + rObject[1],
				lObject[2] + rObject[2],
				lObject[3] + rObject[3]
			);
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator-(T scalar, TMatrix<4, 4, T> const &object) noexcept
		{
			return TMatrix<4, 4, T>
			(
				scalar - object[0],
				scalar - object[1],
				scalar - object[2],
				scalar - object[3]
			);
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator-(TMatrix<4, 4, T> const &object, T scalar) noexcept
		{
			return TMatrix<4, 4, T>
			(
				object[0] - scalar,
				object[1] - scalar,
				object[2] - scalar,
				object[3] - scalar
			);
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator-(TMatrix<4, 4, T> const &lObject, TMatrix<4, 4, T> const &rObject) noexcept
		{
			return TMatrix<4, 4, T>
			(
				lObject[0] - rObject[0],
				lObject[1] - rObject[1],
				lObject[2] - rObject[2],
				lObject[3] - rObject[3]
			);
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator*(T scalar, TMatrix<4, 4, T> const &object) noexcept
		{
			return TMatrix<4, 4, T>
			(
				scalar * object[0],
				scalar * object[1],
				scalar * object[2],
				scalar * object[3]
			);
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator*(TMatrix<4, 4, T> const &object, T scalar) noexcept
		{
			return TMatrix<4, 4, T>
			(
				object[0] * scalar,
				object[1] * scalar,
				object[2] * scalar,
				object[3] * scalar
			);
		}
		template <typename T>
		constexpr TMatrix<4, 2, T> operator*(TMatrix<4, 4, T> const &lObject, TMatrix<4, 2, T> const &rObject) noexcept
		{
			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[1][0];
				T const lObjectC = lObject[2][0];
				T const lObjectD = lObject[3][0];
				T const lObjectE = lObject[0][1];
				T const lObjectF = lObject[1][1];
				T const lObjectG = lObject[2][1];
				T const lObjectH = lObject[3][1];
				T const lObjectI = lObject[0][2];
				T const lObjectJ = lObject[1][2];
				T const lObjectK = lObject[2][2];
				T const lObjectL = lObject[3][2];
				T const lObjectM = lObject[0][3];
				T const lObjectN = lObject[1][3];
				T const lObjectO = lObject[2][3];
				T const lObjectP = lObject[3][3];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[1][0];
				T const rObjectC = rObject[0][1];
				T const rObjectD = rObject[1][1];
				T const rObjectE = rObject[0][2];
				T const rObjectF = rObject[1][2];
				T const rObjectG = rObject[0][3];
				T const rObjectH = rObject[1][3];
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[0][1];
				T const lObjectC = lObject[0][2];
				T const lObjectD = lObject[0][3];
				T const lObjectE = lObject[1][0];
				T const lObjectF = lObject[1][1];
				T const lObjectG = lObject[1][2];
				T const lObjectH = lObject[1][3];
				T const lObjectI = lObject[2][0];
				T const lObjectJ = lObject[2][1];
				T const lObjectK = lObject[2][2];
				T const lObjectL = lObject[2][3];
				T const lObjectM = lObject[3][0];
				T const lObjectN = lObject[3][1];
				T const lObjectO = lObject[3][2];
				T const lObjectP = lObject[3][3];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[0][1];
				T const rObjectC = rObject[1][0];
				T const rObjectD = rObject[1][1];
				T const rObjectE = rObject[2][0];
				T const rObjectF = rObject[2][1];
				T const rObjectG = rObject[3][0];
				T const rObjectH = rObject[3][1];
			#endif

			return TMatrix<4, 2, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectC + lObjectC * rObjectE + lObjectD * rObjectG,
				lObjectA * rObjectB + lObjectB * rObjectD + lObjectC * rObjectF + lObjectD * rObjectH,
				lObjectE * rObjectA + lObjectF * rObjectC + lObjectG * rObjectE + lObjectH * rObjectG,
				lObjectE * rObjectB + lObjectF * rObjectD + lObjectG * rObjectF + lObjectH * rObjectH,
				lObjectI * rObjectA + lObjectJ * rObjectC + lObjectK * rObjectE + lObjectL * rObjectG,
				lObjectI * rObjectB + lObjectJ * rObjectD + lObjectK * rObjectF + lObjectL * rObjectH,
				lObjectM * rObjectA + lObjectN * rObjectC + lObjectO * rObjectE + lObjectP * rObjectG,
				lObjectM * rObjectB + lObjectN * rObjectD + lObjectO * rObjectF + lObjectP * rObjectH
			);
		}
		template <typename T>
		constexpr TMatrix<4, 3, T> operator*(TMatrix<4, 4, T> const &lObject, TMatrix<4, 3, T> const &rObject) noexcept
		{
			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[1][0];
				T const lObjectC = lObject[2][0];
				T const lObjectD = lObject[3][0];
				T const lObjectE = lObject[0][1];
				T const lObjectF = lObject[1][1];
				T const lObjectG = lObject[2][1];
				T const lObjectH = lObject[3][1];
				T const lObjectI = lObject[0][2];
				T const lObjectJ = lObject[1][2];
				T const lObjectK = lObject[2][2];
				T const lObjectL = lObject[3][2];
				T const lObjectM = lObject[0][3];
				T const lObjectN = lObject[1][3];
				T const lObjectO = lObject[2][3];
				T const lObjectP = lObject[3][3];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[1][0];
				T const rObjectC = rObject[2][0];
				T const rObjectD = rObject[0][1];
				T const rObjectE = rObject[1][1];
				T const rObjectF = rObject[2][1];
				T const rObjectG = rObject[0][2];
				T const rObjectH = rObject[1][2];
				T const rObjectI = rObject[2][2];
				T const rObjectJ = rObject[0][3];
				T const rObjectK = rObject[1][3];
				T const rObjectL = rObject[2][3];
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[0][1];
				T const lObjectC = lObject[0][2];
				T const lObjectD = lObject[0][3];
				T const lObjectE = lObject[1][0];
				T const lObjectF = lObject[1][1];
				T const lObjectG = lObject[1][2];
				T const lObjectH = lObject[1][3];
				T const lObjectI = lObject[2][0];
				T const lObjectJ = lObject[2][1];
				T const lObjectK = lObject[2][2];
				T const lObjectL = lObject[2][3];
				T const lObjectM = lObject[3][0];
				T const lObjectN = lObject[3][1];
				T const lObjectO = lObject[3][2];
				T const lObjectP = lObject[3][3];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[0][1];
				T const rObjectC = rObject[0][2];
				T const rObjectD = rObject[1][0];
				T const rObjectE = rObject[1][1];
				T const rObjectF = rObject[1][2];
				T const rObjectG = rObject[2][0];
				T const rObjectH = rObject[2][1];
				T const rObjectI = rObject[2][2];
				T const rObjectJ = rObject[3][0];
				T const rObjectK = rObject[3][1];
				T const rObjectL = rObject[3][2];
			#endif

			return TMatrix<4, 3, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectD + lObjectC * rObjectG + lObjectD * rObjectJ,
				lObjectA * rObjectB + lObjectB * rObjectE + lObjectC * rObjectH + lObjectD * rObjectK,
				lObjectA * rObjectC + lObjectB * rObjectF + lObjectC * rObjectI + lObjectD * rObjectL,
				lObjectE * rObjectA + lObjectF * rObjectD + lObjectG * rObjectG + lObjectH * rObjectJ,
				lObjectE * rObjectB + lObjectF * rObjectE + lObjectG * rObjectH + lObjectH * rObjectK,
				lObjectE * rObjectC + lObjectF * rObjectF + lObjectG * rObjectI + lObjectH * rObjectL,
				lObjectI * rObjectA + lObjectJ * rObjectD + lObjectK * rObjectG + lObjectL * rObjectJ,
				lObjectI * rObjectB + lObjectJ * rObjectE + lObjectK * rObjectH + lObjectL * rObjectK,
				lObjectI * rObjectC + lObjectJ * rObjectF + lObjectK * rObjectI + lObjectL * rObjectL,
				lObjectM * rObjectA + lObjectN * rObjectD + lObjectO * rObjectG + lObjectP * rObjectJ,
				lObjectM * rObjectB + lObjectN * rObjectE + lObjectO * rObjectH + lObjectP * rObjectK,
				lObjectM * rObjectC + lObjectN * rObjectF + lObjectO * rObjectI + lObjectP * rObjectL
			);
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator*(TMatrix<4, 4, T> const &lObject, TMatrix<4, 4, T> const &rObject) noexcept
		{
			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[1][0];
				T const lObjectC = lObject[2][0];
				T const lObjectD = lObject[3][0];
				T const lObjectE = lObject[0][1];
				T const lObjectF = lObject[1][1];
				T const lObjectG = lObject[2][1];
				T const lObjectH = lObject[3][1];
				T const lObjectI = lObject[0][2];
				T const lObjectJ = lObject[1][2];
				T const lObjectK = lObject[2][2];
				T const lObjectL = lObject[3][2];
				T const lObjectM = lObject[0][3];
				T const lObjectN = lObject[1][3];
				T const lObjectO = lObject[2][3];
				T const lObjectP = lObject[3][3];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[1][0];
				T const rObjectC = rObject[2][0];
				T const rObjectD = rObject[3][0];
				T const rObjectE = rObject[0][1];
				T const rObjectF = rObject[1][1];
				T const rObjectG = rObject[2][1];
				T const rObjectH = rObject[3][1];
				T const rObjectI = rObject[0][2];
				T const rObjectJ = rObject[1][2];
				T const rObjectK = rObject[2][2];
				T const rObjectL = rObject[3][2];
				T const rObjectM = rObject[0][3];
				T const rObjectN = rObject[1][3];
				T const rObjectO = rObject[2][3];
				T const rObjectP = rObject[3][3];
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[0][1];
				T const lObjectC = lObject[0][2];
				T const lObjectD = lObject[0][3];
				T const lObjectE = lObject[1][0];
				T const lObjectF = lObject[1][1];
				T const lObjectG = lObject[1][2];
				T const lObjectH = lObject[1][3];
				T const lObjectI = lObject[2][0];
				T const lObjectJ = lObject[2][1];
				T const lObjectK = lObject[2][2];
				T const lObjectL = lObject[2][3];
				T const lObjectM = lObject[3][0];
				T const lObjectN = lObject[3][1];
				T const lObjectO = lObject[3][2];
				T const lObjectP = lObject[3][3];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[0][1];
				T const rObjectC = rObject[0][2];
				T const rObjectD = rObject[0][3];
				T const rObjectE = rObject[1][0];
				T const rObjectF = rObject[1][1];
				T const rObjectG = rObject[1][2];
				T const rObjectH = rObject[1][3];
				T const rObjectI = rObject[2][0];
				T const rObjectJ = rObject[2][1];
				T const rObjectK = rObject[2][2];
				T const rObjectL = rObject[2][3];
				T const rObjectM = rObject[3][0];
				T const rObjectN = rObject[3][1];
				T const rObjectO = rObject[3][2];
				T const rObjectP = rObject[3][3];
			#endif

			return TMatrix<4, 4, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectE + lObjectC * rObjectI + lObjectD * rObjectM,
				lObjectA * rObjectB + lObjectB * rObjectF + lObjectC * rObjectJ + lObjectD * rObjectN,
				lObjectA * rObjectC + lObjectB * rObjectG + lObjectC * rObjectK + lObjectD * rObjectO,
				lObjectA * rObjectD + lObjectB * rObjectH + lObjectC * rObjectL + lObjectD * rObjectP,
				lObjectE * rObjectA + lObjectF * rObjectE + lObjectG * rObjectI + lObjectH * rObjectM,
				lObjectE * rObjectB + lObjectF * rObjectF + lObjectG * rObjectJ + lObjectH * rObjectN,
				lObjectE * rObjectC + lObjectF * rObjectG + lObjectG * rObjectK + lObjectH * rObjectO,
				lObjectE * rObjectD + lObjectF * rObjectH + lObjectG * rObjectL + lObjectH * rObjectP,
				lObjectI * rObjectA + lObjectJ * rObjectE + lObjectK * rObjectI + lObjectL * rObjectM,
				lObjectI * rObjectB + lObjectJ * rObjectF + lObjectK * rObjectJ + lObjectL * rObjectN,
				lObjectI * rObjectC + lObjectJ * rObjectG + lObjectK * rObjectK + lObjectL * rObjectO,
				lObjectI * rObjectD + lObjectJ * rObjectH + lObjectK * rObjectL + lObjectL * rObjectP,
				lObjectM * rObjectA + lObjectN * rObjectE + lObjectO * rObjectI + lObjectP * rObjectM,
				lObjectM * rObjectB + lObjectN * rObjectF + lObjectO * rObjectJ + lObjectP * rObjectN,
				lObjectM * rObjectC + lObjectN * rObjectG + lObjectO * rObjectK + lObjectP * rObjectO,
				lObjectM * rObjectD + lObjectN * rObjectH + lObjectO * rObjectL + lObjectP * rObjectP
			);
		}
		template <typename T>
		constexpr typename TMatrix<4, 4, T>::data_t operator*(TMatrix<4, 4, T> const &matrix, typename TMatrix<4, 4, T>::data_t const &vector) noexcept
		{
			return typename TMatrix<4, 4, T>::data_t
			(
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					matrix[0][0] * vector.x + matrix[1][0] * vector.y + matrix[2][0] * vector.z + matrix[3][0] * vector.w,
					matrix[0][1] * vector.x + matrix[1][1] * vector.y + matrix[2][1] * vector.z + matrix[3][1] * vector.w,
					matrix[0][2] * vector.x + matrix[1][2] * vector.y + matrix[2][2] * vector.z + matrix[3][2] * vector.w,
					matrix[0][3] * vector.x + matrix[1][3] * vector.y + matrix[2][3] * vector.z + matrix[3][3] * vector.w
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z + matrix[0][3] * vector.w,
					matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z + matrix[1][3] * vector.w,
					matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z + matrix[2][3] * vector.w,
					matrix[3][0] * vector.x + matrix[3][1] * vector.y + matrix[3][2] * vector.z + matrix[3][3] * vector.w
				#endif
			);
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator/(T scalar, TMatrix<4, 4, T> const &object) noexcept
		{
			return TMatrix<4, 4, T>
			(
				scalar / object[0],
				scalar / object[1],
				scalar / object[2],
				scalar / object[3]
			);
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator/(TMatrix<4, 4, T> const &object, T scalar) noexcept
		{
			return TMatrix<4, 4, T>
			(
				object[0] / scalar,
				object[1] / scalar,
				object[2] / scalar,
				object[3] / scalar
			);
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator/(TMatrix<4, 4, T> const &lObject, TMatrix<4, 4, T> const &rObject) noexcept
		{
			return TMatrix<4, 4, T>
			(
				lObject[0] / rObject[0],
				lObject[1] / rObject[1],
				lObject[2] / rObject[2],
				lObject[3] / rObject[3]
			);
		}
		template <typename T>
		constexpr typename TMatrix<4, 4, T>::data_t operator/(TMatrix<4, 4, T> const& matrix, typename TMatrix<4, 4, T>::data_t const &vector) noexcept
		{
			return detail::ComputeInverse(matrix) * vector;
		}

		template <typename T>
		constexpr bool operator==(TMatrix<4, 4, T> const &lObject, TMatrix<4, 4, T> const &rObject) noexcept
		{
			return
			(
				lObject[0] == rObject[0] &&
				lObject[1] == rObject[1] &&
				lObject[2] == rObject[2] &&
				lObject[3] == rObject[3]
			);
		}
		template <typename T>
		constexpr bool operator!=(TMatrix<4, 4, T> const &lObject, TMatrix<4, 4, T> const &rObject) noexcept
		{
			return
			(
				lObject[0] != rObject[0] ||
				lObject[1] != rObject[1] ||
				lObject[2] != rObject[2] ||
				lObject[3] != rObject[3]
			);
		}
	}
}

#endif