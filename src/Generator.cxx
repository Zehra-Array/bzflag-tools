/* bzflag
 * Copyright (c) 1993 - 2007 Tim Riker
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named COPYING that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#include "Generator.h"

void Generator::parseOptions(Options opt) {
  size = 800;
  bases = 0;

  if (opt->Exists("s"))     { size = opt->GetDataI("s"); }
  if (opt->Exists("-size")) { size = opt->GetDataI("-size"); }

  if (opt->Exists("b"))      { bases = opt->GetDataI("b"); }
  if (opt->Exists("-bases")) { bases = opt->GetDataI("-bases"); }
}
  
void Generator::run() {

}

void Generator::output(std::ofstream& out ) {
  out << "world\n";
  out << "  name BZWGen Generated City\n";
  out << "  size " << int(size / 2) << "\n";
  out << "end\n\n";
}


// Local Variables: ***
// mode:C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8