# downstream_src_a

The package of the `srcext` distribution of the
[REP 159](https://github.com/openrobotics/reps/pull/32) test harness.
`srcext` extends the `upstream` distribution with
`extension_method: source_rebuild`, so a CI job that asks for this package
with its dependencies checks out and builds `upstream_c`, `upstream_b` and
`upstream_a` from source too. Reads a YAML document with libyaml. Plain
CMake package, no ROS dependency.

Index and distribution files: https://github.com/rep159-testing/rep159-rosdistro
