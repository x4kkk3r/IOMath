#ifndef _IO_MATH_TMATRIX_3X4_HPP
#define _IO_MATH_TMATRIX_3X4_HPP

#include "../vectors/TVector3.hpp"
#include "../vectors/TVector4.hpp"

#include <cassert>

namespace IOMath
{
	namespace Types
	{
		template <typename T>
		struct TMatrix<3, 4, T>
		{
			typedef TVector<4, T> row_t;
			typedef TVector<3, T> column_t;
		private:
			row_t data[3];
		public:
			constexpr TMatrix() noexcept = default;
			constexpr TMatrix(TMatrix const &other) noexcept = default;
			constexpr explicit TMatrix(T scalar) noexcept :
				data
				{
					row_t(scalar, 0, 0, 0),
					row_t(0, scalar, 0, 0),
					row_t(0, 0, scalar, 0)
				} {}
			constexpr TMatrix(T a1, T a2, T a3, T a4, T b1, T b2, T b3, T b4, T c1, T c2, T c3, T c4) noexcept :
				data
				{
					row_t(a1, a2, a3, a4),
					row_t(b1, b2, b3, b4),
					row_t(c1, c2, c3, c4)
				} {}
			constexpr TMatrix(row_t const &firstRow, row_t const &secondRow, row_t const &thirdRow) noexcept :
				data
				{
					row_t(firstRow),
					row_t(secondRow),
					row_t(thirdRow)
				} {}

			template <typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J, typename K, typename L>
			constexpr TMatrix(A a, B b, C c, D d, E e, F f, G g, H h, I i, J j, K k, L l) noexcept :
				data
				{
					row_t(a, b, c, d),
					row_t(e, f, g, h),
					row_t(i, j, k, l)
				} {}
			template <typename A, typename B, typename C>
			constexpr TMatrix(TVector<4, A> const &firstRow, TVector<4, B> const &secondRow, TVector<4, C> const &thirdRow) noexcept :
				data
				{
					row_t(firstRow),
					row_t(secondRow),
					row_t(thirdRow)
				} {}

			template <typename U>
			constexpr TMatrix(TMatrix<2, 2, U> const &other) noexcept :
				data
				{
					row_t(other[0], 0, 0),
					row_t(other[1], 0, 0),
					row_t()
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<2, 3, U> const &other) noexcept :
				data
				{
					row_t(other[0], 0),
					row_t(other[1], 0),
					row_t()
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<2, 4, U> const &other) noexcept :
				data
				{
					row_t(other[0]),
					row_t(other[1]),
					row_t()
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<3, 2, U> const &other) noexcept :
				data
				{
					row_t(other[0], 0, 0),
					row_t(other[1], 0, 0),
					row_t(other[2], 0, 0)
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<3, 3, U> const &other) noexcept :
				data
				{
					row_t(other[0], 0),
					row_t(other[1], 0),
					row_t(other[2], 0)
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<3, 4, U> const &other) noexcept :
				data
				{
					row_t(other[0]),
					row_t(other[1]),
					row_t(other[2])
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<4, 2, U> const &other) noexcept :
				data
				{
					row_t(other[0], 0, 0),
					row_t(other[1], 0, 0),
					row_t(other[2], 0, 0)
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<4, 3, U> const &other) noexcept :
				data
				{
					row_t(other[0], 0),
					row_t(other[1], 0),
					row_t(other[2], 0)
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<4, 4, U> const &other) noexcept :
				data
				{
					row_t(other[0]),
					row_t(other[1]),
					row_t(other[2])
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<3, 2, U> const &otherA, TMatrix<3, 2, U> const &otherB) noexcept :
				data
				{
					row_t(otherA[0], otherB[0]),
					row_t(otherA[1], otherB[1]),
					row_t(otherA[2], otherB[2])
				} {}

			static constexpr size_t Rows() noexcept
			{
				return column_t::Size();
			}
			static constexpr size_t Columns() noexcept
			{
				return row_t::Size();
			}

			constexpr row_t& operator[](size_t index) noexcept
			{
				assert(index >= 0 && index < TMatrix::Rows());
				return data[index];
			}
			constexpr row_t const& operator[](size_t index) const noexcept
			{
				assert(index >= 0 && index < TMatrix::Rows());
				return data[index];
			}
		
			template <typename U>
			constexpr TMatrix<3, 4, T>& operator=(TMatrix<3, 4, U> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
				this->data[2] = other[2];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 4, T>& operator+=(U scalar) noexcept
			{
				this->data[0] += scalar;
				this->data[1] += scalar;
				this->data[2] += scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 4, T>& operator+=(TMatrix<3, 4, U> const &other) noexcept
			{
				this->data[0] += other[0];
				this->data[1] += other[1];
				this->data[2] += other[2];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 4, T>& operator-=(U scalar) noexcept
			{
				this->data[0] -= scalar;
				this->data[1] -= scalar;
				this->data[2] -= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 4, T>& operator-=(TMatrix<3, 4, U> const &other) noexcept
			{
				this->data[0] -= other[0];
				this->data[1] -= other[1];
				this->data[2] -= other[2];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 4, T>& operator*=(U scalar) noexcept
			{
				this->data[0] *= scalar;
				this->data[1] *= scalar;
				this->data[2] *= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 4, T>& operator/=(U scalar) noexcept
			{
				this->data[0] /= scalar;
				this->data[1] /= scalar;
				this->data[2] /= scalar;

				return *this;
			}

			constexpr TMatrix<3, 4, T>& operator++() noexcept
			{
				++this->data[0];
				++this->data[1];
				++this->data[2];

				return *this;
			}
			constexpr TMatrix<3, 4, T>& operator--() noexcept
			{
				--this->data[0];
				--this->data[1];
				--this->data[2];

				return *this;
			}
			constexpr TMatrix<3, 4, T>& operator++(int) noexcept
			{
				TMatrix<3, 4, T> result = TMatrix<3, 4, T>(*this);

				++*this;

				return result;
			}
			constexpr TMatrix<3, 4, T>& operator--(int) noexcept
			{
				TMatrix<3, 4, T> result = TMatrix<3, 4, T>(*this);

				--*this;

				return result;
			}
		};

		template <typename T>
		constexpr TMatrix<3, 4, T> operator+(TMatrix<3, 4, T> const &object) noexcept
		{
			return object;
		}
		template <typename T>
		constexpr TMatrix<3, 4, T> operator-(TMatrix<3, 4, T> const &object) noexcept
		{
			return TMatrix<3, 4, T>
			(
				-object[0],
				-object[1],
				-object[2]
			);
		}
	
		template <typename T>
		constexpr TMatrix<3, 4, T> operator+(T scalar, TMatrix<3, 4, T> const &object) noexcept
		{
			return TMatrix<3, 4, T>(object) += scalar;
		}
		template <typename T>
		constexpr TMatrix<3, 4, T> operator+(TMatrix<3, 4, T> const &object, T scalar) noexcept
		{
			return TMatrix<3, 4, T>(object) += scalar;
		}
		template <typename T>
		constexpr TMatrix<3, 4, T> operator+(TMatrix<3, 4, T> const &lObject, TMatrix<3, 4, T> const &rObject) noexcept
		{
			return TMatrix<3, 4, T>(lObject) += rObject;
		}
		template <typename T>
		constexpr TMatrix<3, 4, T> operator-(T scalar, TMatrix<3, 4, T> const &object) noexcept
		{
			return TMatrix<3, 4, T>
			(
				scalar - object[0],
				scalar - object[1],
				scalar - object[2]
			);
		}
		template <typename T>
		constexpr TMatrix<3, 4, T> operator-(TMatrix<3, 4, T> const &object, T scalar) noexcept
		{
			return TMatrix<3, 4, T>(object) -= scalar;
		}
		template <typename T>
		constexpr TMatrix<3, 4, T> operator-(TMatrix<3, 4, T> const &lObject, TMatrix<3, 4, T> const &rObject) noexcept
		{
			return TMatrix<3, 4, T>(lObject) -= rObject;
		}
		template <typename T>
		constexpr TMatrix<3, 4, T> operator*(T scalar, TMatrix<3, 4, T> const &object) noexcept
		{
			return TMatrix<3, 4, T>(object) *= scalar;
		}
		template <typename T>
		constexpr TMatrix<3, 4, T> operator*(TMatrix<3, 4, T> const &object, T scalar) noexcept
		{
			return TMatrix<3, 4, T>(object) *= scalar;
		}
		template <typename T>
		constexpr TMatrix<3, 2, T> operator*(TMatrix<3, 4, T> const &lObject, TMatrix<4, 2, T> const &rObject) noexcept
		{
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

			T const rObjectA = rObject[0][0];
			T const rObjectB = rObject[0][1];
			T const rObjectC = rObject[1][0];
			T const rObjectD = rObject[1][1];
			T const rObjectE = rObject[2][0];
			T const rObjectF = rObject[2][1];
			T const rObjectG = rObject[3][0];
			T const rObjectH = rObject[3][1];

			return TMatrix<3, 2, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectC + lObjectC * rObjectE + lObjectD * rObjectG,
				lObjectA * rObjectB + lObjectB * rObjectD + lObjectC * rObjectF + lObjectD * rObjectH,
				lObjectE * rObjectA + lObjectF * rObjectC + lObjectG * rObjectE + lObjectH * rObjectG,
				lObjectE * rObjectB + lObjectF * rObjectD + lObjectG * rObjectF + lObjectH * rObjectH,
				lObjectI * rObjectA + lObjectJ * rObjectC + lObjectK * rObjectE + lObjectL * rObjectG,
				lObjectI * rObjectB + lObjectJ * rObjectD + lObjectK * rObjectF + lObjectL * rObjectH
			);
		}
		template <typename T>
		constexpr TMatrix<3, 3, T> operator*(TMatrix<3, 4, T> const &lObject, TMatrix<4, 3, T> const &rObject) noexcept
		{
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

			return TMatrix<3, 3, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectD + lObjectC * rObjectG + lObjectD * rObjectJ,
				lObjectA * rObjectB + lObjectB * rObjectE + lObjectC * rObjectH + lObjectD * rObjectK,
				lObjectA * rObjectC + lObjectB * rObjectF + lObjectC * rObjectI + lObjectD * rObjectL,
				lObjectE * rObjectA + lObjectF * rObjectD + lObjectG * rObjectG + lObjectH * rObjectJ,
				lObjectE * rObjectB + lObjectF * rObjectE + lObjectG * rObjectH + lObjectH * rObjectK,
				lObjectE * rObjectC + lObjectF * rObjectF + lObjectG * rObjectI + lObjectH * rObjectL,
				lObjectI * rObjectA + lObjectJ * rObjectD + lObjectK * rObjectG + lObjectL * rObjectJ,
				lObjectI * rObjectB + lObjectJ * rObjectE + lObjectK * rObjectH + lObjectL * rObjectK,
				lObjectI * rObjectC + lObjectJ * rObjectF + lObjectK * rObjectI + lObjectL * rObjectL
			);
		}
		template <typename T>
		constexpr TMatrix<3, 4, T> operator*(TMatrix<3, 4, T> const &lObject, TMatrix<4, 4, T> const &rObject) noexcept
		{
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

			return TMatrix<3, 4, T>
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
				lObjectI * rObjectD + lObjectJ * rObjectH + lObjectK * rObjectL + lObjectL * rObjectP
			);
		}
		template <typename T>
		constexpr TMatrix<3, 4, T> operator/(T scalar, TMatrix<3, 4, T> const &object) noexcept
		{
			return TMatrix<3, 4, T>
			(
				scalar / object[0],
				scalar / object[1],
				scalar / object[2]
			);
		}
		template <typename T>
		constexpr TMatrix<3, 4, T> operator/(TMatrix<3, 4, T> const &object, T scalar) noexcept
		{
			return TMatrix<3, 4, T>(object) /= scalar;
		}
		
		template <typename T>
		constexpr bool operator==(TMatrix<3, 4, T> const &lObject, TMatrix<3, 4, T> const &rObject) noexcept
		{
			return
			(
				lObject[0] == rObject[0] &&
				lObject[1] == rObject[1] &&
				lObject[2] == rObject[2]
			);
		}
		template <typename T>
		constexpr bool operator!=(TMatrix<3, 4, T> const &lObject, TMatrix<3, 4, T> const &rObject) noexcept
		{
			return !(lObject == rObject);
		}
	}
}

#endif