#pragma once
#include "std.hpp"
#include "utils.hpp"
#include "logger.hpp"

// 定义 Business Messages ID
constexpr int SequenceReset_1 = 1;
constexpr int Sequence_2 = 2;
constexpr int SecurityStatus = 3;
constexpr int EmptyBook_9 = 9;
constexpr int SecurityGroupPhase = 10;
constexpr int SecurityDefinition = 12;
constexpr int OpeningPrice = 15;
constexpr int TheoreticalOpeningPrice = 16;
constexpr int ClosingPrice = 17;
constexpr int AuctionImbalance = 19;
constexpr int PriceBand = 22;
constexpr int QuantityBand = 21;
constexpr int HighPrice = 24;
constexpr int LowPrice = 25;
constexpr int LastTradePrice = 27;
constexpr int SettlementPrice = 28;
constexpr int OpenInterest = 29;
constexpr int ExecutionStatistics = 56;
constexpr int Order_MBO = 50;
constexpr int DeleteOrder_MBO = 51;
constexpr int MassDeleteOrders_MBO = 52;
constexpr int Trade = 53;
constexpr int ForwardTrade = 54;
constexpr int ExecutionSummary = 55;
constexpr int SnapshotFullRefresh_Orders_MBO = 71;

#include "AggressorSide.h"
#include "ApplVerID.h"
#include "AuctionImbalance_19.h"
#include "Boolean.h"
#include "ChannelReset_11.h"
#include "ClosingPrice_17.h"
#include "DeleteOrder_MBO_51.h"
#include "EmptyBook_9.h"
#include "ExecutionStatistics_56.h"
#include "ExecutionSummary_55.h"
#include "ExerciseStyle.h"
#include "Fixed8.h"
#include "ForwardTrade_54.h"
#include "FramingHeader.h"
#include "GovernanceIndicator.h"
#include "GroupSizeEncoding.h"
#include "HeaderMessage_0.h"
#include "HighPrice_24.h"
#include "ImbalanceCondition.h"
#include "ImpliedMarketIndicator.h"
#include "InstrAttribType.h"
#include "InstrAttribValue.h"
#include "LastTradePrice_27.h"
#include "LotType.h"
#include "LowPrice_25.h"
#include "MDEntryType.h"
#include "MDUpdateAction.h"
#include "MassDeleteOrders_MBO_52.h"
#include "MatchEventIndicator.h"
#include "MaturityMonthYear.h"
#include "MessageHeader.h"
#include "MessageType.h"
#include "MultiLegModel.h"
#include "MultiLegPriceMethod.h"
#include "NewsSource.h"
#include "News_5.h"
#include "OpenCloseSettlFlag.h"
#include "OpenInterest_29.h"
#include "OpeningPrice_15.h"
#include "Order_MBO_50.h"
#include "PacketHeader.h"
#include "Percentage.h"
#include "Price.h"
#include "Price8.h"
#include "PriceBandMidpointPriceType.h"
#include "PriceBandType.h"
#include "PriceBand_22.h"
#include "PriceLimitType.h"
#include "PriceOffset8Optional.h"
#include "PriceOptional.h"
#include "PriceType.h"
#include "Product.h"
#include "PutOrCall.h"
#include "QuantityBand_21.h"
#include "RatioQty.h"
#include "SecurityDefinition_12.h"
#include "SecurityGroupPhase_10.h"
#include "SecurityIDSource.h"
#include "SecurityMatchType.h"
#include "SecurityStatus_3.h"
#include "SecurityTradingEvent.h"
#include "SecurityTradingStatus.h"
#include "SecurityType.h"
#include "SecurityUpdateAction.h"
#include "SequenceReset_1.h"
#include "Sequence_2.h"
#include "SettlPriceType.h"
#include "SettlementPrice_28.h"
#include "Side.h"
#include "SnapshotFullRefresh_Header_30.h"
#include "SnapshotFullRefresh_Orders_MBO_71.h"
#include "TextEncoding.h"
#include "TheoreticalOpeningPrice_16.h"
#include "TradeBust_57.h"
#include "TradeCondition.h"
#include "Trade_53.h"
#include "TradingSessionID.h"
#include "TradingSessionSubID.h"
#include "TrdSubType.h"
#include "UTCTimestampNanos.h"
#include "UTCTimestampSeconds.h"
#include "VarString.h"
