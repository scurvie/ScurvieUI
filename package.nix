{ stdenv
, clang_16
, meson
, cmake
, pkg-config
, ninja
}:

stdenv.mkDerivation {
  name = "ScurvieUI";
  src = ./.;

  nativeBuildInputs = [
    clang_16
    meson
    cmake
    pkg-config
    ninja
  ];

  buildInputs = [];
}
