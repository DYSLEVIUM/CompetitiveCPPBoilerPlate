template <typename T>
class Vector3d {
  T x, y, z;

 public:
  explicit Vector3d(T xx = 0, T yy = 0, T zz = 0) : x(xx), y(yy), z(zz) {}

  T get_x() const { return this->x; }
  T get_y() const { return this->y; }
  T get_z() const { return this->z; }

  T dot(const Vector3d<T>& vec) const {
    return this->x * vec.x + this->y * vec.y + this->z * vec.z;
  }

  Vector3d<T> cross(const Vector3d<T>& vec) const {
    return Vector3d<T>(this->y * vec.z - vec.y * this->z,
                       this->x * vec.z - vec.x * this->z,
                       this->x * vec.y - vec.x * this->y);
  }

  T normalize() const { return this->dot(*this); }

  ld absolute() const { return sqrt(this->normalize()); }

  Vector3d& operator+=(const Vector3d<T>& vec) {
    this->x += vec.x;
    this->y += vec.y;
    this->z += vec.z;

    return *this;
  }

  Vector3d& operator-=(const Vector3d<T>& vec) {
    this->x -= vec.x;
    this->y -= vec.y;
    this->z -= vec.z;

    return *this;
  }

  Vector3d& operator*=(const T& scalar) {
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;

    return *this;
  }

  Vector3d& operator/=(const T& scalar) {
    this->x /= scalar;
    this->y /= scalar;
    this->z /= scalar;

    return *this;
  }

  bool operator==(const Vector3d<T>& vec) const {
    return this->x == vec.x && this->y == vec.y && this->z == vec.z;
  }

  bool operator!=(const Vector3d<T>& vec) const {
    return this->x != vec.x || this->y != vec.y || this->z != vec.z;
  }

  Vector3d<T> operator+(const Vector3d<T>& vec) const {
    return Vector3d<T>(*this) += vec;
  }

  Vector3d<T> operator-(const Vector3d<T>& vec) const {
    return Vector3d<T>(*this) -= vec;
  }

  Vector3d<T> operator*(const T& scalar) const {
    return Vector3d<T>(*this) *= scalar;
  }

  Vector3d<T> operator/(const T& scalar) const {
    return Vector3d<T>(*this) /= scalar;
  }

  friend istream& operator>>(istream& is, Vector3d<T>& vec) {
    is >> vec.x >> vec.y >> vec.z;
    return is;
  }

  friend ostream& operator<<(ostream& os, const Vector3d<T>& vec) {
    os << vec.x << ' ' << vec.y << ' ' << vec.z;
    return os;
  }
};
