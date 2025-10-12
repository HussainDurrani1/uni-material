# 📚 Study Notes

## 📋 Content Summary
This document covers the vector and parametric equations of a line in 3D space, and how to calculate the distance from a point to a line in 3D. It starts by recalling 2D line equations and then transitions to 3D, defining lines using a point and a direction vector. Several examples illustrate how to find these equations and calculate distances.

## 🎯 Key Points

*   **Vector Equation of a Line in 3D:** A line in 3D space can be represented by a vector equation using a known point on the line and a direction vector.
*   **Parametric Equations of a Line in 3D:** From the vector equation, we can derive three scalar parametric equations, one for each coordinate (x, y, z), where each equation depends on a parameter 't'.
*   **Finding the Direction Vector:** The direction vector of a line can be found by:
    *   Being given directly.
    *   Being parallel to another given line (using its direction vector).
    *   Being perpendicular to two given vectors (using their cross product).
    *   Being the vector connecting two points on the line.
*   **Line Segment Parameterization:** To parameterize a line segment between two points, we first find the general parametric equation of the line and then determine the range of the parameter 't' that corresponds to the segment.
*   **Distance from a Point to a Line in 3D:** The shortest distance from a point to a line is the length of the perpendicular segment from the point to the line. This distance can be calculated using a formula involving the cross product of vectors.

## 💡 Detailed Explanation

### Vector Equation of a Line in 3D 🚀

A line `L` in 3D space is uniquely determined by a point `P₀(x₀, y₀, z₀)` on the line and a direction vector `v` parallel to the line.

Let `P(x, y, z)` be any arbitrary point on the line `L`. Let `r₀` be the position vector of `P₀` and `r` be the position vector of `P`. The vector from `P₀` to `P` is denoted by `u`.

By the Triangle Law of vector addition, we have:
`r = r₀ + u`

Since `u` is parallel to the direction vector `v`, there exists a scalar `t` such that `u = tv`. Substituting this into the equation above, we get the vector equation of the line:
`r = r₀ + tv`

Here, `t` is a scalar parameter that can take any real value (`t ∈ R`). Each value of `t` corresponds to a unique point on the line.

### Parametric Equations of a Line in 3D 📝

If the direction vector `v` is given in component form as `v = <a, b, c>`, and the position vector `r₀` is `<x₀, y₀, z₀>`, then the vector equation `r = r₀ + tv` becomes:

`<x, y, z> = <x₀, y₀, z₀> + t<a, b, c>`
`<x, y, z> = <x₀ + ta, y₀ + tb, z₀ + tc>`

For two vectors to be equal, their corresponding components must be equal. This gives us the three scalar parametric equations of the line:

*   `x = x₀ + ta`
*   `y = y₀ + tb`
*   `z = z₀ + tc`

where `t ∈ R`.

### Finding the Direction Vector 🧭

The direction vector `v` is crucial for defining a line in 3D. Here are common ways to find it:

1.  **Given Directly:** The problem might explicitly state the direction vector (e.g., `v = 2i + 4j - 2k`).
2.  **Parallel to Another Line:** If a line is parallel to another line with a known direction vector, then that direction vector can be used.
3.  **Perpendicular to Two Vectors:** If a line is perpendicular to two vectors, say `u` and `v`, its direction vector can be found by taking the cross product of `u` and `v` (`w = u × v`).
4.  **Connecting Two Points:** If a line passes through two points `P` and `Q`, the direction vector can be found by forming the vector `PQ` (i.e., `Q - P`).

### Parameterization of a Line Segment 📍

To parameterize a line segment between two points, say `P` and `Q`:

1.  **Find the Equation of the Line:** First, determine the parametric equation of the line passing through `P` and `Q` using the methods described above.
2.  **Determine the Range of `t`:** Find the specific values of the parameter `t` that correspond to the endpoints `P` and `Q`. This will define the domain of `t` for the line segment. For example, if `t=0` corresponds to point `P` and `t=1` corresponds to point `Q`, then the line segment is parameterized by `t` in the interval `[0, 1]`.

### Distance from a Point to a Line in Space 📏

Let `L` be a line with a direction vector `v`, and let `P₀` be a point in space from which we want to find the distance to the line. Let `P₁` be any point on the line `L`.

The vector `u` from `P₁` to `P₀` is given by `u = r₀ - r₁`, where `r₀` and `r₁` are the position vectors of `P₀` and `P₁`, respectively.

The shortest distance `s` from `P₀` to the line `L` is the length of the perpendicular segment from `P₀` to `L`. This distance can be calculated using the formula:

`s = |u × v| / |v|`

where:
*   `u` is the vector from a point on the line (`P₁`) to the given point (`P₀`).
*   `v` is the direction vector of the line.
*   `|u × v|` is the magnitude of the cross product of `u` and `v`.
*   `|v|` is the magnitude of the direction vector `v`.

## 🔑 Key Concepts

*   **Vector Equation of a Line:** `r = r₀ + tv` (Represents all points on a line using a starting point and a direction vector scaled by a parameter `t`).
*   **Parametric Equations of a Line:** `x = x₀ + ta`, `y = y₀ + tb`, `z = z₀ + tc` (Scalar equations derived from the vector equation).
*   **Direction Vector:** A vector parallel to the line, indicating its orientation in space.
*   **Parameter `t`:** A scalar variable that ranges over real numbers (or a specific interval for a line segment), defining points along the line.
*   **Cross Product:** An operation on two vectors that results in a vector perpendicular to both input vectors. Used to find a direction vector perpendicular to two given vectors.
*   **Magnitude of a Vector:** The length of a vector, calculated using the Pythagorean theorem in 3D: `|aî + bĵ + ck| = √(a² + b² + c²)`.
*   **Line Segment:** A portion of a line defined by two endpoints, typically parameterized by restricting the range of the parameter `t`.

## 📝 Learning Summary

This document provides a comprehensive introduction to representing lines in 3D space using vector and parametric equations. It emphasizes the importance of the direction vector and how to derive it from various given conditions. The key takeaway is the ability to define any point on a line using a starting point and a scaled direction vector. Furthermore, the document introduces a practical method for calculating the shortest distance from an external point to a line in 3D space, utilizing vector cross products and magnitudes.

**Suggestions for Further Study:**
*   Practice more problems involving finding the intersection of lines, the angle between lines, and determining if lines are parallel, intersecting, or skew.
*   Explore the concept of the equation of a plane in 3D and its relationship with lines.
*   Investigate different forms of line equations (e.g., symmetric equations).

## 🤔 Reflection Questions

1.  How does the concept of a direction vector in 3D differ from the slope in 2D, and what are the advantages of using vectors in 3D?
2.  When calculating the distance from a point to a line, why is the cross product and its magnitude essential? What would happen if we only used the dot product?
3.  Consider the parameter `t` in the parametric equations of a line. What does it physically represent, and how does its range (e.g., `(-∞, ∞)`, `[0, 1]`, `[a, b]`) affect the geometric interpretation of the equation?