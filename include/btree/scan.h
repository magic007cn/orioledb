/*-------------------------------------------------------------------------
 *
 * scan.h
 *		Declarations for sequential scan of OrioleDB B-tree.
 *
 * Copyright (c) 2021-2022, Oriole DB Inc.
 *
 * IDENTIFICATION
 *	  contrib/orioledb/include/btree/scan.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef __BTREE_SCAN_H__
#define __BTREE_SCAN_H__

#include "btree/btree.h"
#include "btree/page_contents.h"

#include "executor/tuptable.h"

typedef struct BTreeSeqScan BTreeSeqScan;

typedef struct BTreeSeqScanCallbacks
{
	bool		(*isRangeValid) (OTuple low, OTuple high, void *arg);
	bool		(*getNextKey) (OFixedKey *key, bool inclusive, void *arg);
} BTreeSeqScanCallbacks;

extern BTreeSeqScan *make_btree_seq_scan(BTreeDescr *desc, CommitSeqNo csn);
extern BTreeSeqScan *make_btree_seq_scan_cb(BTreeDescr *desc, CommitSeqNo csn,
											BTreeSeqScanCallbacks *cb,
											void *arg);
extern OTuple btree_seq_scan_getnext(BTreeSeqScan *scan, MemoryContext mctx,
									 CommitSeqNo *tupleCsn,
									 BTreeLocationHint *hint);
extern OTuple btree_seq_scan_getnext_raw(BTreeSeqScan *scan, MemoryContext mctx,
										 bool *end, BTreeLocationHint *hint);
extern void free_btree_seq_scan(BTreeSeqScan *scan);
extern void seq_scans_cleanup(void);

#endif							/* __BTREE_SCAN_H__ */
