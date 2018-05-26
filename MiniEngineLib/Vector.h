#pragma once

namespace MiniEngineLib
{
	template <class BaseType>
	class Vector
	{
	public :

		using TypeVec = Vector<BaseType>;

		Vector() = default;
		Vector(BaseType X, BaseType Y, BaseType Z = 0);
		~Vector() = default;

		Vector<BaseType> operator+(const Vector<BaseType>& rhs);
		Vector<BaseType> operator-(const Vector<BaseType>& rhs);
		Vector<BaseType> operator*(const Vector<BaseType>& rhs);
		Vector<BaseType> operator/(const Vector<BaseType>& rhs);
		Vector<BaseType> operator=(const Vector<BaseType>& rhs);
		bool operator==(const Vector<BaseType>& rhs);

		BaseType _x;
		BaseType _y;
		BaseType _z;
	};

	template<class BaseType>
	inline Vector<BaseType>::Vector(BaseType X, BaseType Y, BaseType Z)
	{
		_x = X;
		_y = Y;
		_z = Z;
	}

	template<class BaseType>
	inline Vector<BaseType> Vector<BaseType>::operator+(const Vector<BaseType>& rhs)
	{
		return Vector<BaseType>(_x + rhs._x, _y + rhs._y, _z + rhs._z);
	}

	template<class BaseType>
	inline Vector<BaseType> Vector<BaseType>::operator-(const Vector<BaseType>& rhs)
	{
		return Vector<BaseType>(_x - rhs._x, _y - rhs._y, _z - rhs._z);
	}

	template<class BaseType>
	inline Vector<BaseType> Vector<BaseType>::operator*(const Vector<BaseType>& rhs)
	{
		return Vector<BaseType>(_x * rhs._x, _y * rhs._y, _z * rhs._z);
	}

	template<class BaseType>
	inline Vector<BaseType> Vector<BaseType>::operator/(const Vector<BaseType>& rhs)
	{
		return Vector<BaseType>(_x / rhs._x, _y / rhs._y, _z / rhs._z);
	}

	template<class BaseType>
	inline Vector<BaseType> Vector<BaseType>::operator=(const Vector<BaseType>& rhs)
	{
		return Vector<BaseType>(_x, _y, _z);
	}

	template<class BaseType>
	inline bool Vector<BaseType>::operator==(const Vector<BaseType>& rhs)
	{
		if (_x == rhs._x
			&& _y == rhs._y
			&& _z == rhs._z)
		{
			return true;
		}

		return false;
	}
}
