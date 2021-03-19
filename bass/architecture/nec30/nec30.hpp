struct Nec30 : Architecture {
  Nec30(Bass& self);
  auto assemble(const string& statement) -> bool override;
};
