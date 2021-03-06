/*****************************************************************************/
/*                                                                           */
/* Copyright (c) 2011-2013 Seoul National University.                        */
/* All rights reserved.                                                      */
/*                                                                           */
/* Redistribution and use in source and binary forms, with or without        */
/* modification, are permitted provided that the following conditions        */
/* are met:                                                                  */
/*   1. Redistributions of source code must retain the above copyright       */
/*      notice, this list of conditions and the following disclaimer.        */
/*   2. Redistributions in binary form must reproduce the above copyright    */
/*      notice, this list of conditions and the following disclaimer in the  */
/*      documentation and/or other materials provided with the distribution. */
/*   3. Neither the name of Seoul National University nor the names of its   */
/*      contributors may be used to endorse or promote products derived      */
/*      from this software without specific prior written permission.        */
/*                                                                           */
/* THIS SOFTWARE IS PROVIDED BY SEOUL NATIONAL UNIVERSITY "AS IS" AND ANY    */
/* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED */
/* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE    */
/* DISCLAIMED. IN NO EVENT SHALL SEOUL NATIONAL UNIVERSITY BE LIABLE FOR ANY */
/* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL        */
/* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   */
/* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)     */
/* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,       */
/* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  */
/* ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE          */
/* POSSIBILITY OF SUCH DAMAGE.                                               */
/*                                                                           */
/* Contact information:                                                      */
/*   Center for Manycore Programming                                         */
/*   School of Computer Science and Engineering                              */
/*   Seoul National University, Seoul 151-744, Korea                         */
/*   http://aces.snu.ac.kr                                                   */
/*                                                                           */
/* Contributors:                                                             */
/*   Sangmin Seo, Jungwon Kim, Gangwon Jo, Jun Lee, Jeongho Nah,             */
/*   Jungho Park, Junghyun Kim, and Jaejin Lee                               */
/*                                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* This file is based on the SNU-SAMSUNG OpenCL Compiler and is distributed  */
/* under GNU General Public License.                                         */
/* See LICENSE.SNU-SAMSUNG_OpenCL_C_Compiler.TXT for details.                */
/*****************************************************************************/

#ifndef SNUCLC_TRANSFORMLOCALVD_H
#define SNUCLC_TRANSFORMLOCALVD_H

#include "clang/AST/PrettyPrinter.h"
#include "CLOptions.h"
#include "CLUtils.h"
#include "CLExpressions.h"
#include "StmtTransformer.h"

namespace clang {
namespace snuclc {

/// TransformLocalVD
/// Find VarDecls declared inside a function and add sizes of all local 
/// VarDecls.
class TransformLocalVD : public StmtTransformer {
  ASTContext    &ASTCtx;
  CLOptions     &CLOpts;
  CLExpressions &CLExprs;
  VarDeclSetTy  &LocalVDSet;
  uint64_t LocalMemSize;
  uint64_t PrivateMemSize;
  unsigned PointerSize;

  llvm::raw_ostream &OS;
  PrintingPolicy &Policy;

public:
  TransformLocalVD(ASTContext &C, CLOptions &Opts, CLExpressions &Exprs,
      FunctionDecl *FD, VarDeclSetTy &LVDSet)
    : ASTCtx(C), CLOpts(Opts), CLExprs(Exprs), LocalVDSet(LVDSet),
      OS(llvm::errs()), Policy(C.PrintingPolicy) {
    LocalMemSize = 0;
    PrivateMemSize = 0;
    PointerSize = (CLOpts.M64 == 1) ? 64 : 32;
    Transform(FD);
  }

  void Transform(FunctionDecl *FD);

  uint64_t getLocalMemSize()    { return LocalMemSize; }
  uint64_t getPrivateMemSize()  { return PrivateMemSize; }

  CompoundStmt *TransformRawCompoundStmt(CompoundStmt *Node);
  Stmt *TransformRawDeclStmt(DeclStmt *S);
  Stmt *TransformRawIfStmt(IfStmt *If);

  Stmt *VisitNullStmt(NullStmt *Node);
  Stmt *VisitCompoundStmt(CompoundStmt *Node);
  Stmt *VisitLabelStmt(LabelStmt *Node);
  Stmt *VisitIfStmt(IfStmt *If);
  Stmt *VisitSwitchStmt(SwitchStmt *Node);
  Stmt *VisitWhileStmt(WhileStmt *Node);
  Stmt *VisitDoStmt(DoStmt *Node);
  Stmt *VisitForStmt(ForStmt *Node);
  Stmt *VisitGotoStmt(GotoStmt *Node);
  Stmt *VisitIndirectGotoStmt(IndirectGotoStmt *Node);
  Stmt *VisitContinueStmt(ContinueStmt *Node);
  Stmt *VisitBreakStmt(BreakStmt *Node);
  Stmt *VisitReturnStmt(ReturnStmt *Node);
  Stmt *VisitDeclStmt(DeclStmt *Node);
  Stmt *VisitCaseStmt(CaseStmt *Node);
  Stmt *VisitDefaultStmt(DefaultStmt *Node);

  Stmt *VisitPredefinedExpr(PredefinedExpr *Node);
  Stmt *VisitDeclRefExpr(DeclRefExpr *Node);
  Stmt *VisitIntegerLiteral(IntegerLiteral *Node);
  Stmt *VisitFloatingLiteral(FloatingLiteral *Node);
  Stmt *VisitImaginaryLiteral(ImaginaryLiteral *Node);
  Stmt *VisitStringLiteral(StringLiteral *Str);
  Stmt *VisitCharacterLiteral(CharacterLiteral *Node);
  Stmt *VisitParenExpr(ParenExpr *Node);
  Stmt *VisitUnaryOperator(UnaryOperator *Node);
  Stmt *VisitOffsetOfExpr(OffsetOfExpr *Node);
  Stmt *VisitSizeOfAlignOfExpr(SizeOfAlignOfExpr *Node);
  Stmt *VisitVecStepExpr(VecStepExpr *Node);
  Stmt *VisitArraySubscriptExpr(ArraySubscriptExpr *Node);
  Stmt *VisitCallExpr(CallExpr *Call);
  Stmt *VisitMemberExpr(MemberExpr *Node);
  Stmt *VisitBinaryOperator(BinaryOperator *Node);
  Stmt *VisitCompoundAssignOperator(CompoundAssignOperator *Node);
  Stmt *VisitConditionalOperator(ConditionalOperator *Node);
  Stmt *VisitImplicitCastExpr(ImplicitCastExpr *Node);
  Stmt *VisitCStyleCastExpr(CStyleCastExpr *Node);
  Stmt *VisitCompoundLiteralExpr(CompoundLiteralExpr *Node);
  Stmt *VisitExtVectorElementExpr(ExtVectorElementExpr *Node);
  Stmt *VisitInitListExpr(InitListExpr* Node);
  Stmt *VisitDesignatedInitExpr(DesignatedInitExpr *Node);
  Stmt *VisitParenListExpr(ParenListExpr* Node);
  Stmt *VisitVAArgExpr(VAArgExpr *Node);
}; //end class TransformLocalVD

} //end namespace snuclc
} //end namespace clang

#endif //SNUCLC_TRANSFORMLOCALVD_H

