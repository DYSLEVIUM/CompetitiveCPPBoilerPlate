template <typename T>
class Vector2d {
  T x, y;

 public:
  explicit Vector2d(T xx = 0, T yy = 0) : x(xx), y(yy) {}

  T get_x() const { return this->x; }
  T get_y() const { return this->y; }

  T dot(const Vector2d<T>& vec) const {
    return this->x * vec.x + this->y * vec.y;
  }

  T area(const Vector2d<T>& vec_1, const Vector2d<T>& vec_2) const {
    //  vector w.r.t this
    Vector2d<T> vec_t_1 = vec_1 - *this, vec_t_2 = vec_2 - *this;
    return vec_t_1.get_y() * vec_t_2.get_x() -
           vec_t_2.get_y() * vec_t_1.get_x();
  }

  T normalize() const { return this->dot(*this); }

  ld absolute() const { return sqrt(this->normalize()); }

  Vector2d& operator+=(const Vector2d<T>& vec) {
    this->x += vec.x;
    this->y += vec.y;

    return *this;
  }

  Vector2d& operator-=(const Vector2d<T>& vec) {
    this->x -= vec.x;
    this->y -= vec.y;

    return *this;
  }

  Vector2d& operator*=(const T& scalar) {
    this->x *= scalar;
    this->y *= scalar;

    return *this;
  }

  Vector2d& operator/=(const T& scalar) {
    this->x /= scalar;
    this->y /= scalar;

    return *this;
  }

  bool operator==(const Vector2d<T>& vec) const {
    return this->x == vec.x && this->y == vec.y;
  }

  bool operator!=(const Vector2d<T>& vec) const {
    return this->x != vec.x || this->y != vec.y;
  }

  Vector2d<T> operator+(const Vector2d<T>& vec) const {
    return Vector2d<T>(*this) += vec;
  }

  Vector2d<T> operator-(const Vector2d<T>& vec) const {
    return Vector2d<T>(*this) -= vec;
  }

  Vector2d<T> operator*(const T& scalar) const {
    return Vector2d<T>(*this) *= scalar;
  }

  Vector2d<T> operator/(const T& scalar) const {
    return Vector2d<T>(*this) /= scalar;
  }

  friend istream& operator>>(istream& is, Vector2d<T>& vec) {
    is >> vec.x >> vec.y;
    return is;
  }

  friend ostream& operator<<(ostream& os, const Vector2d<T>& vec) {
    os << vec.x << ' ' << vec.y;
    return os;
  }
};
