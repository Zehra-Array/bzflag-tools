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
/** 
 * @file PlanarGraph.h
 * @author Kornel Kisielewicz kornel.kisielewicz@gmail.com
 * @brief Defines an Graph class.
*/

#ifndef __PLANARGRAPH_H__
#define __PLANARGRAPH_H__

#include "graph/forward.h"
#include "graph/Node.h"
#include "graph/Edge.h"
#include "graph/Face.h"

namespace graph {

/** 
 * @class PlanarGraph
 * @brief Class defining double linked planar graph. 
 */
class PlanarGraph
{
private:
  /** The list of all Node s. */
  NodeList nodeList;
  /** The list of all Edge s. */
  EdgeList edgeList;
  /** The list of all Face s. */
  FaceList faceList;
  /** Holds the number of nodes */
  size_t nodes;
  /** Holds the number of edges */
  size_t edges;
public:
  /** Default constructor. Creates an empty graph.*/
  PlanarGraph() : nodes(0), edges(0) {} 
  /** Destructor.*/
  virtual ~PlanarGraph() {}
  /** Adds a node to the graph. As convienience returns the passed edge. */
  virtual NodePtr addNode( NodePtr node ) {
    nodeList.add( node );
    node->setGraph( this );
    ++nodes;
    return node;
  }
  /** Adds a single edge to the graph. As convienience returns the passed edge. */
  virtual EdgePtr addEdge( EdgePtr edge ) {
    edgeList.add( edge );
    ++edges;
    return edge;
  }
  /** Returns the number of nodes */
  size_t nodeCount() const { 
    return nodes;
  }
  /** Returns the number of edges */
  size_t edgeCount() const { 
    return edges;
  }
  /** Returns node by ID */
  NodePtr getNode( size_t id ) {
    return nodeList.get(id);
  }
  /** Returns edge by ID */
  EdgePtr getEdge( size_t id ) {
    return edgeList.get(id);
  }
  /** Removes a given Edge from the graph. Note that it DOES dispose of the edge object. */
  void removeEdge( size_t id ) {
    delete edgeList.get(id);
    edgeList.clear(id);
  }
  /** 
   * Removes a given Node from the graph. Also removes all 
     connected edges, as they are no longer valid. Note that 
     it DOES dispose of the node object and edge objects. */
  void removeNode( size_t id ) {
    NodePtr node = nodeList.get(id);
    node->orphanize();
    delete node;
    nodeList.clear(id);
  }

};


}// end namespace graph


#endif // __PLANARGRAPH_H__

// Local Variables: ***
// mode:C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8