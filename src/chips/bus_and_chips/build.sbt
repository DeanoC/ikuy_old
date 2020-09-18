lazy val spinalCore = ProjectRef(uri("git://github.com/deanoc/SpinalHDL.git#dev"), "core")
lazy val spinalLib = ProjectRef(uri("git://github.com/deanoc/SpinalHDL.git#dev"), "lib")
lazy val spinalPlugin = ProjectRef(uri("git://github.com/deanoc/SpinalHDL.git#dev"), "idslplugin")

lazy val buildSettings = Seq(
  organization := "com.deanoc",
  version := "0.0.1",
  scalaVersion := "2.11.12",
  scalacOptions += (artifactPath in(spinalPlugin, Compile, packageBin)).map { file =>
    s"-Xplugin:${file.getAbsolutePath}"
  }.value,
  licenses := Seq("The MIT License (MIT)" -> url("http://opensource.org/licenses/MIT"))
)

lazy val all = (project in file("."))
  .dependsOn(spinalCore)
  .dependsOn(spinalLib)
  .dependsOn(spinalPlugin)
  .settings(
    buildSettings
  )
